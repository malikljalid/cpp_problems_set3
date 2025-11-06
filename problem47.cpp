#include <iostream>
#include <fstream>
#include <string>
#include <limits>

struct stBankRecord
{
    std::string Name;
    std::string PhoneNumber;
    std::string AccountNumber;
    short int   PinCode;
    short int   Balance;
};

std::string convertBankRecordToLine(stBankRecord BR, std::string delim = ":")
{
    return (BR.Name + delim + BR.PhoneNumber + delim + BR.AccountNumber + delim + std::to_string(BR.PinCode) + delim + std::to_string(BR.Balance));
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

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return (BR);
}

void addLineToFile(std::string line, std::string fileName)
{
    std::fstream file;

    file.open(fileName, std::ios::app);

    if (file.is_open())
    {
        file << line << std::endl;
        file.close();
    }
}

void addRecordsToFile(std::string fileName)
{
    bool userWantAddMore = true;

    while (userWantAddMore)
    {
        std::cout << "--- Adding a new client ---\n\n";
        addLineToFile(convertBankRecordToLine(readBankRecord()), fileName);
        std::cout << "\nClient Added Successfuly, Do you want add more (0-No / 1-Yes) ? : ";
        std::cin >> userWantAddMore;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main(void)
{
    addRecordsToFile("ListOfClientsData.txt");

    return (0);
}
