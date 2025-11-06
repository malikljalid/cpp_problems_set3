#include <iostream>
#include <string>

struct stBankRecord
{
    std::string Name;
    std::string PhoneNumber;
    std::string AccountNumber;
    short int   PinCode;
    int         Balance;
};

std::string convertBankRecordToOneLine(stBankRecord BR, std::string delim = ":")
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

    return (BR);
}

int main(void)
{
    std::cout << convertBankRecordToOneLine(readBankRecord()) << std::endl;

    return (0);
}
