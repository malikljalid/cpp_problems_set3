#include <iostream>
#include <string>

void printFirstCharacterOfEachWordIn(std::string msg)
{
    std::string::iterator iter;
    bool isFirstLetter = true;

    for (iter = msg.begin(); iter < msg.end(); iter++)
    {
        if (isFirstLetter && *iter != ' ')
        {
            std::cout << *iter << std::endl;
            isFirstLetter = false;
        }
        if (*iter == ' ')
            isFirstLetter = true;
    }
}

int main(void)
{
    printFirstCharacterOfEachWordIn("Hello     World 2025 you have 2 months to end");

    return (0);
}
