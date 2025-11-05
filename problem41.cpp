#include <iostream>
#include <string>
#include <vector>

//----------------- method 1 -------------------
std::vector <std::string> splitReversed(std::string msg)
{
    int                         end     = (int)msg.length();
    int                         j       = 0;
    std::vector <std::string>   vWords;

    for (int i = end - 1; i > 0; i--)
    {
        j = i;
        while (msg[i] != ' ' && i < end)
        {
            if (msg[i-1] == ' ')
                vWords.push_back(msg.substr(i, j - i + 1));
            i--;
        }
    }

    return (vWords);
}

std::string joinVectorStrings(std::vector <std::string> vStrings, char delim)
{
    std::string fullString = "";

    for (std::vector <std::string>::iterator i = vStrings.begin(); i != vStrings.end(); i++)
        fullString.append(*i + delim);

    return (fullString.substr(0, fullString.length() - 1));
}


//---------------- method 2 --------------------
std::vector <std::string> split(std::string msg)
{
    int                         end   = (int)msg.length();
    int                         j = 0;
    std::vector <std::string>   vWords;

    for (int i = 0; i < end; i++)
    {
        j = i;
        while (msg[i] != ' ' && i < end)
        {
            if (msg[i+1] == ' ')
                vWords.push_back(msg.substr(j, i - j + 1));
            i++;
        }
    }

    return (vWords);
}

std::string joinVectorStringsReversed(std::vector <std::string> vStrings, char delim)
{
    std::string fullString = "";
    std::vector <std::string>::iterator i = vStrings.end();

    for (i--; i != vStrings.begin(); i--)
        fullString.append(*i + delim);
    fullString.append(*vStrings.begin() + delim);

    return (fullString.substr(0, fullString.length() - 1));
}

int main(void)
{
    std::string msg = "  Hello World, it's 2025!  ";

    std::cout << joinVectorStrings(splitReversed(msg), ' ') << std::endl;
    std::cout << joinVectorStringsReversed(split(msg), ' ') << std::endl;

    return (0);
}
