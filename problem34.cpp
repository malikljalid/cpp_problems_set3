#include <iostream>
#include <string>

bool letterIsVowel(char c)
{
    c = tolower(c);

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void printVowelsInString(std::string msg)
{
    std::cout << "Vowels in string are : ";
    for (char & c : msg)
    {
        if (letterIsVowel(c))
            std::cout << c << ' ';
    }

    std::cout << std::endl;
}

int main(void)
{
    std::string msg = "Hello world, howzza going?\n";

    std::cout << msg << std::endl;
    printVowelsInString(msg);

    return (0);
}
