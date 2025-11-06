#include <iostream>
#include <string>

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

void printBankRecord(stBankRecord BR)
{
    std::cout << "Name           : " << BR.Name << std::endl;

    std::cout << "Phone Number   : " <<  BR.PhoneNumber << std::endl;

    std::cout << "Account Number : " << BR.AccountNumber << std::endl;

    std::cout << "PinCode : " << BR.PinCode << std::endl;

    std::cout << "Balance : " << BR.Balance << std::endl;
}

int main(void)
{
    stBankRecord BankRecord = convertLineToBankRecord("Zakaria Adriouche:::0660200613:::ZA132006:::1234:::7000", ":::");

    printBankRecord(BankRecord);

    return (0);
}
