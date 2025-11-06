#include <iostream>
#include <vector>
#include <string>

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

std::string joinVectorStrings(std::vector <std::string> vStrings, char delim)
{
    std::string fullString = "";
    std::vector <std::string>::iterator i;

    for (i = vStrings.begin(); i != vStrings.end(); i++)
        fullString.append(*i + delim);

    return (fullString.substr(0, fullString.length() - 1));
}

std::string removePungs(std::string msg)
{
    for (int i = 0; (size_t)i < msg.length(); i++)
    {
        if (ispunct(msg[i]))
            msg[i] = ' ';
    }

    return (msg);
}

std::string removeAllPungs(std::string msg)
{
    return (joinVectorStrings(split(removePungs(msg)), ' '));
}

int main(void)
{
    std::cout << removeAllPungs("Hello World, I AM :CREPY: all Right :( ") << std::endl;

    return (0);
}
