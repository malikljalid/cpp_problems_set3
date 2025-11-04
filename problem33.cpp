#include <iostream>
#include <string>

bool letterIsVowel(char c)
{
    c = tolower(c);

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int getVowelsCountInString(std::string msg)
{
    int vowels = 0;

    for (char & c : msg)
    {
        if (letterIsVowel(c))
            vowels++;
    }

    return (vowels);
}

int main(void)
{
    std::cout << getVowelsCountInString("Hello world, howzza going?\n") << std::endl;

    return (0);
}
