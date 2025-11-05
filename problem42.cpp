#include <iostream>
#include <string>
#include <vector>

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
            if (msg[i+1] == ' ' || i == end - 1)
                vWords.push_back(msg.substr(j, i - j + 1));
            i++;
        }
    }

    return (vWords);
}

std::string joinVectorStrings(std::vector <std::string> &vStrings, char delim)
{
    std::string fullString = "";
    std::vector <std::string>::iterator i;

    for (i = vStrings.begin(); i != vStrings.end(); i++)
        fullString.append(*i + delim);

    return (fullString.substr(0, fullString.length() - 1));
}

std::string findAndReplaceIn(std::string msg, std::string toFind, std::string toReplace)
{
    std::vector <std::string> vWords = split(msg);

    for (std::string & word : vWords)
    {
        if (word == toFind)
            word = toReplace;
    }

    return (joinVectorStrings(vWords, ' '));
}

int main(void)
{
    std::cout << findAndReplaceIn("Hello World i am sad so much", "sad", "happy") << std::endl;

    return (0);
}
