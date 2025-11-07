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

void printBankRecord(stBankRecord BR)
{
    std::cout << "Name           : " << BR.Name << std::endl;

    std::cout << "Phone Number   : " << BR.PhoneNumber << std::endl;

    std::cout << "Account Number : " << BR.AccountNumber << std::endl;

    std::cout << "PinCode : " << BR.PinCode << std::endl;

    std::cout << "Balance : " << BR.Balance << std::endl;
}

std::string readAccountNumber(void)
{
    std::string AccountNumber;

    std::cout << "Please enter Account Number to search for : ";
    std::cin >> AccountNumber;

    return (AccountNumber);
}

stBankRecord readBankRecord(void)
{
    stBankRecord BR;

    std::cout << "Please enter your name : ";
    getline(std::cin, BR.Name);

    std::cout << "Please enter your phone number : ";
    std::cin >> BR.PhoneNumber;

    std::cout << "Please enter your Account Number : ";
    std::cin >> BR.AccountNumber;

    std::cout << "Please enter your PinCode : ";
    std::cin >> BR.PinCode;

    std::cout << "Please enter your Balance : ";
    std::cin >> BR.Balance;

    return (BR);
}

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

std::string convertBankRecordToLine(stBankRecord BR, std::string delim = ":")
{
    return (BR.Name + delim + BR.PhoneNumber + delim + BR.AccountNumber + delim + std::to_string(BR.PinCode) + delim + std::to_string(BR.Balance));
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

std::vector <stBankRecord> LoadDataFromFileToVector(std::string fileName, std::string delim, std::string ExceptionClientAccountNumber)
{
    std::fstream                file;
    std::vector <stBankRecord>  vRecords;
    stBankRecord                BR;

    file.open(fileName, std::ios::in);

    if (file.is_open())
    {
        std::string Line = "";

        while (getline(file, Line))
        {
            BR = convertLineToBankRecord(Line, delim);
            if (BR.AccountNumber == ExceptionClientAccountNumber)
                BR = readBankRecord();
            vRecords.push_back(BR);

        }
        file.close();
    }

    return (vRecords);
}

stBankRecord getRecordInList(std::string fileName, std::string delim, std::string AccountNumberToFind)
{
    std::vector <stBankRecord>  vRecords = LoadDataFromFileToVector(fileName, delim);
    stBankRecord                NOTFOUND = {"", "", "", 0, 0};

    for (std::vector <stBankRecord>::iterator i = vRecords.begin(); i != vRecords.end(); i++)
    {
        if ((*i).AccountNumber == AccountNumberToFind)
            return (*i);
    }
    return (NOTFOUND);
}

void saveDataFromVectorToFile(std::vector <stBankRecord> &vRecords, std::string fileName, std::string delim)
{
    std::fstream file;

    file.open(fileName, std::ios::out);

    if (file.is_open())
    {
        for (stBankRecord & i : vRecords)
        {
            file << convertBankRecordToLine(i, delim) << std::endl;
        }
        file.close();
    }
}

void updateClient(std::string fileName, std::string delim, std::string toUpdate)
{
    std::vector <stBankRecord> vNewRecords = LoadDataFromFileToVector(fileName, delim, toUpdate);

    saveDataFromVectorToFile(vNewRecords, fileName, delim);
}

int main(void)
{
    std::string  toFindAccountNumber = readAccountNumber();
    stBankRecord client = getRecordInList("clients_bankRecords.txt", ":", toFindAccountNumber);

    if (client.AccountNumber.empty())
        std::cout << "Client With Account Number " << toFindAccountNumber << " NOT FOUND!\n";
    else
    {
        char choice;

        std::cout << "\n-- The following are the clients details --\n";
        printBankRecord(client);

        std::cout << "Are you sure you want to update this client (Yes-y / No-n) ? : ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 'y')
        {
            updateClient("clients_bankRecords.txt", ":", toFindAccountNumber);
            std::cout << "\nClient Updated Successfuly!\n";
        }
    }

    return (0);
}
