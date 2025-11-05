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

int main(void)
{
    std::string msg = "   Hello world,    hozza going  !!  ";

    std::vector <std::string> words = split(msg);

    for (std::string & i : words)
    {
        std::cout << i << std::endl;
    }

    return (0);
}
