#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

struct stBankRecord
{
    std::string Name;
    std::string PhoneNumber;
    std::string AccountNumber;
    short int   PinCode;
    short int   Balance;
};

void fillBankRecordInfo(std::string &bankRecordInfo, std::string &line, std::string delim)
{
    int i = line.find(delim);
    bankRecordInfo = line.substr(0, i);
    line.erase(0, i + delim.length());
}

void fillBankRecordInfo(short int &bankRecordInfo, std::string &line, std::string delim)
{
    int i = line.find(delim);
    bankRecordInfo = std::stoi(line.substr(0, i));
    line.erase(0, i + delim.length());
}

stBankRecord convertLineToBankRecord(std::string line, std::string delim = ":")
{
    stBankRecord    BR;

    fillBankRecordInfo(BR.Name, line, delim);
    fillBankRecordInfo(BR.PhoneNumber, line, delim);
    fillBankRecordInfo(BR.AccountNumber, line, delim);
    fillBankRecordInfo(BR.PinCode, line, delim);
    fillBankRecordInfo(BR.Balance, line, delim);

    return (BR);
}

std::vector <stBankRecord> LoadDataFromFileToVector(std::string fileName, std::string delim)
{
    std::fstream                file;
    std::vector <stBankRecord>  vRecords;

    file.open(fileName, std::ios::in);

    if (file.is_open())
    {
        std::string Line = "";

        while (getline(file, Line))
            vRecords.push_back(convertLineToBankRecord(Line, delim));;
        file.close();
    }

    return (vRecords);
}

void printHeader(std::vector <stBankRecord> vClients)
{
    std::cout << "\n\t\t\t    Client List(" << vClients.size() << ") Client(s)\n";
    std::cout << "  ______________________________________________________________________________\n\n";
    std::cout << " | " << std::setw(15) << std::left << "Account Number";
    std::cout << " | " << std::setw(9)  << std::left << "Pin Code";
    std::cout << " | " << std::setw(20) << std::left << "Client Name";
    std::cout << " | " << std::setw(12) << std::left << "Phone";
    std::cout << " | " << std::setw(6)  << std::left << "Balance |\n";
    std::cout << "  ______________________________________________________________________________\n\n";

    for (std::vector <stBankRecord>::iterator  i = vClients.begin(); i != vClients.end(); i++)
    {
        std::cout << " | " << std::setw(15) << (*i).AccountNumber;
        std::cout << " | " << std::setw(9)  << (*i).PinCode;
        std::cout << " | " << std::setw(20) << (*i).Name;
        std::cout << " | " << std::setw(12) << (*i).PhoneNumber;
        std::cout << " | " << std::setw(6)  << (*i).Balance << "  |\n";
    }

    std::cout << "  ______________________________________________________________________________\n\n";
}

int main(void)
{
    printHeader(LoadDataFromFileToVector("ListOfClientsData.txt", ":"));

    return (0);
}
