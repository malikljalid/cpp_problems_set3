#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

enum enMenuOptions { LIST=1, ADD, DELETE, UPDATE, FIND, EXIT };

struct stListFile
{
    std::string Name;
    std::string Delim;
};

struct stBankRecord
{
    std::string Name;
    std::string PhoneNumber;
    std::string AccountNumber;
    short int   PinCode;
    short int   Balance;
};

struct stBankMenu
{   
    stListFile                      ListFile;
    std::vector <stBankRecord>      vListVector;
    enMenuOptions                   Operation;
};

stBankRecord readBankRecord(void)
{
    stBankRecord BR;

    std::cout << "Please enter your name : ";
    getline(std::cin, BR.Name);

    std::cout << "Please enter your Phone number : ";
    std::cin >> BR.PhoneNumber;

    std::cout << "Please enter your Account Number : ";
    std::cin >> BR.AccountNumber;

    std::cout << "Please enter your PinCode : ";
    std::cin >> BR.PinCode;

    std::cout << "Please enter your Balance : ";
    std::cin >> BR.Balance;

    return (BR);
}

stBankRecord readBankRecord(std::string ClientID)
{
    stBankRecord BR;

    std::cout << "Please enter your name : ";
    getline(std::cin, BR.Name);

    std::cout << "Please enter your Phone number : ";
    std::cin >> BR.PhoneNumber;

    BR.AccountNumber = ClientID;

    std::cout << "Please enter your PinCode : ";
    std::cin >> BR.PinCode;

    std::cout << "Please enter your Balance : ";
    std::cin >> BR.Balance;

    return (BR);
}

std::string readAccountNumber(void)
{
    std::string AccountNumber;

    std::cout << "\nPlease enter an Account Number : ";
    std::cin >> AccountNumber;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return (AccountNumber);
}

enMenuOptions readUserOperation(void)
{
    short int choice;

    std::cout << "\nChoose what do you want to do [1 ~ 6] ? : ";
    std::cin >> choice;

    return ((enMenuOptions)choice);
}

void printBankRecord(stBankRecord BR)
{
    std::cout << "Name           : " << BR.Name << std::endl;

    std::cout << "Phone Number   : " << BR.PhoneNumber << std::endl;

    std::cout << "Account Number : " << BR.AccountNumber << std::endl;

    std::cout << "PinCode : " << BR.PinCode << std::endl;

    std::cout << "Balance : " << BR.Balance << std::endl;
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

std::string  convertBankRecordToLine(stBankRecord BR, std::string delim = ":")
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
                BR = readBankRecord(ExceptionClientAccountNumber);
            vRecords.push_back(BR);

        }
        file.close();
    }

    return (vRecords);
}

std::vector <stBankRecord> LoadDataFromFileToVectorExceptFor(std::string fileName, std::string delim, std::string ExceptionClientAccountNumber)
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
            if (BR.AccountNumber != ExceptionClientAccountNumber)
                vRecords.push_back(BR);
        }
        file.close();
    }

    return (vRecords);
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

bool clientExistInList(stListFile file, std::string AccountNumberToFind)
{
    std::vector <stBankRecord>  vRecords = LoadDataFromFileToVector(file.Name, file.Delim);

    for (std::vector <stBankRecord>::iterator i = vRecords.begin(); i != vRecords.end(); i++)
    {
        if ((*i).AccountNumber == AccountNumberToFind)
            return (true);
    }
    return (false);
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

void addRecordToFile( std::string ClientID, stListFile file)
{
        std::cout << "--- Adding a new client ---\n\n";
        addLineToFile(convertBankRecordToLine(readBankRecord(ClientID), file.Delim), file.Name);
        std::cout << "\nClient Added Successfuly!\n";
}

void updateClient(stListFile file, std::string toUpdate)
{
    std::vector <stBankRecord> vNewRecords;
    
    if (clientExistInList(file, toUpdate) == false)
        std::cout << "Account " << toUpdate << " does not exist!\n";
    else
    {
        vNewRecords = LoadDataFromFileToVector(file.Name, file.Delim, toUpdate);
        saveDataFromVectorToFile(vNewRecords, file.Name, file.Delim);
        std::cout << "Client " << toUpdate << " Updated Successfuly!\n\n";
    }
}

void deleteClient(stListFile file, std::string toDelete)
{
    std::vector <stBankRecord> vNewRecords;

    if (clientExistInList(file, toDelete) == false)
        std::cout << "Account " << toDelete << " does not exist!\n";
    else
    {
        vNewRecords = LoadDataFromFileToVectorExceptFor(file.Name, file.Delim, toDelete);
        saveDataFromVectorToFile(vNewRecords, file.Name, file.Delim);
        std::cout << "Client " << toDelete << " Deleted Successfuly!\n\n";
    }
}

void findClient(stListFile file, std::string toFindAccountNumber)
{
    stBankRecord client = getRecordInList(file.Name, file.Delim, toFindAccountNumber);

    if (client.AccountNumber.empty())
        std::cout << "Client With Account Number " << toFindAccountNumber << " NOT FOUND!\n";
    else
    {
        std::cout << "\n-- The following are the clients details --\n";
        printBankRecord(client);
    }
}

void addClient(std::string ClientID, stBankMenu &Menu)
{
    if (clientExistInList(Menu.ListFile, ClientID))
        std::cout << "Account " << ClientID << " already exist!\n";
    else
        addRecordToFile(ClientID, Menu.ListFile);
}

stBankMenu initMenu(std::string fileName, std::string delim)
{
    stBankMenu Menu;

    Menu.ListFile.Name = fileName;
    Menu.ListFile.Delim = delim;
    Menu.vListVector = LoadDataFromFileToVector(fileName, delim);

    return (Menu);
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

void showMenuOf(enMenuOptions Option)
{
    std::cout << "---------------------------------------\n";
    switch (Option)
    {
        case (ADD) :
        {
            std::cout << "|\t    Add Client Screen          |\n";
            break;
        }
        case (DELETE) :
        {
            std::cout << "|\t    Delete Client Screen       |\n";
            break;
        }
        case (UPDATE) :
        {
            std::cout << "|\t    Update Client Screen        |\n";
            break;
        }
        case (FIND) :
        {
            std::cout << "|\t    Find Client Screen          |\n";
            break;
        }
        case (EXIT) :
        {
            std::cout << "|\t    Program ENDS :)           |\n";
        }
        default :
            break;
    }
    std::cout << "---------------------------------------\n";
}

void showMenu(void)
{
    std::cout << "---------------------------------------\n";
    std::cout << "|\t    Main Menu Screen          |\n";
    std::cout << "---------------------------------------\n";
    std::cout << "\t[1] : Show Clients List\n";
    std::cout << "\t[2] : Add New Client\n";
    std::cout << "\t[3] : Delete Client\n";
    std::cout << "\t[4] : Update Client Info\n";
    std::cout << "\t[5] : Find Client\n";
    std::cout << "\t[6] : Exit\n";
    std::cout << "---------------------------------------\n";
    std::cout << "---------------------------------------\n";
}

void executeUserOperation(stBankMenu &Menu)
{
    switch (Menu.Operation)
    {
        case (LIST) :
        {
            printHeader(Menu.vListVector);
            break;
        }
        case (ADD)  :
        {
            showMenuOf(ADD);
            addClient(readAccountNumber(), Menu);
            break;
        }
        case (FIND) :
        {
            showMenuOf(FIND);
            findClient(Menu.ListFile, readAccountNumber());
            break;
        }
        case (DELETE) :
        {
            showMenuOf(DELETE);
            deleteClient(Menu.ListFile, readAccountNumber());
            break;
        }
        case (UPDATE) :
        {
            showMenuOf(UPDATE);
            updateClient(Menu.ListFile, readAccountNumber());
            break;
        }
        case (EXIT) :
            break;
    }

    if (Menu.Operation == ADD || Menu.Operation == DELETE || Menu.Operation == UPDATE)
        Menu.vListVector = LoadDataFromFileToVector(Menu.ListFile.Name, Menu.ListFile.Delim);
}

int main(void)
{
    stBankMenu Menu = initMenu("clients_bankRecords.txt", ":");

    while (true)
    {
        showMenu();
        Menu.Operation = readUserOperation();
        if (Menu.Operation == EXIT)
        {
            showMenuOf(EXIT);
            break;
        }
        executeUserOperation(Menu);
    }

    return (0);
}

