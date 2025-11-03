#include <iostream>
#include <string>
#include <cctype>

std::string lowerFirstCharacterOfEachWordIn(std::string msg)
{
    bool isFirstLetter = true;

    for (std::string::iterator iter = msg.begin(); iter < msg.end(); iter++)
    {
        if (*iter != ' ' && isFirstLetter)
        {
            if (isupper(*iter))
                *iter = tolower(*iter);
            isFirstLetter = false;
        }
        
        if (*iter == ' ')
            isFirstLetter = true;
    }

    return (msg);
}

int main(void)
{
    std::string msg = "  Hello     World 2025 @you Have 2 months to The END ";

    msg = lowerFirstCharacterOfEachWordIn(msg);

    std::cout << msg << std::endl;

    return (0);
}
