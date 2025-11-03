#include <iostream>
#include <string>
#include <cctype>

void upperFirstCharacterOfEachWordIn(std::string &msg)
{
    bool isFirstLetter = true;

    for (std::string::iterator iter = msg.begin(); iter < msg.end(); iter++)
    {
        if (*iter != ' ' && isFirstLetter)
        {
            if (islower(*iter))
                *iter = toupper(*iter);
            isFirstLetter = false;
        }
        
        if (*iter == ' ')
            isFirstLetter = true;
    }
}

int main(void)
{
    std::string msg = "  Hello     World 2025 @you have 2 months to end ";

    upperFirstCharacterOfEachWordIn(msg);

    std::cout << msg << std::endl;

    return (0);
}
