#include <iostream>
#include <string>
#include <vector>

enum enArraySize { MAXSIZE=100 };

std::string joinVectorStrings(std::vector <std::string> &vStrings, char delim)
{
    std::string fullString = "";

    for (std::vector <std::string>::iterator i = vStrings.begin(); i != vStrings.end(); i++)
        fullString.append(*i + delim);

    return (fullString.substr(0, fullString.length() - 1));
}

std::string joinVectorStrings(std::string arr[MAXSIZE], short int size, char delim)
{
    std::string fullString = "";

    for (short int i = 0; i < size; i++)
        fullString.append(arr[i] + delim);

    return (fullString.substr(0, fullString.length() - 1));
}

int main(void)
{
    std::vector <std::string> vList  { "Josh", "Mike", "Delama" };
    std::string      List[MAXSIZE] = { "Josh", "Mike", "Delama" };
    short int        listSize = 3;

    std::cout << joinVectorStrings(vList, ':') << std::endl;
    std::cout << joinVectorStrings(List, listSize, ':') << std::endl;

    return (0);
}
