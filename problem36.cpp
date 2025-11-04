#include <iostream>
#include <string>

int getWordsCountInString(std::string msg)
{
    int end     = (int)msg.length();
    int words   = 0;

    for (int i = 0; i < end; i++)
    {
        while (msg[i] != ' ' && i < end)
        {
            if (msg[i+1] == ' ')
                words++;
            i++;
        }
    }

    return (words);
}

int main(void)
{
    std::string msg = "   Hello world,    hozza going  !!  ";

    std::cout << "Number of Words in \" " << msg << "\" is : " << getWordsCountInString(msg) << std::endl;

    return (0);
}
