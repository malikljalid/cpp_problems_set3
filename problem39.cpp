#include <iostream>
#include <string>
#include <vector>

std::string joinVectorStrings(std::vector <std::string> &vStrings, char delim)
{
    std::string fullString = "";

    for (std::vector <std::string>::iterator i = vStrings.begin(); i != vStrings.end(); i++)
        fullString.append(*i + delim);

    return (fullString.substr(0, fullString.length() - 1));
}

int main(void)
{
    std::vector <std::string> vList { "Josh", "Mike", "Delama" };

    std::cout << joinVectorStrings(vList, ':') << std::endl;

    return (0);
}
