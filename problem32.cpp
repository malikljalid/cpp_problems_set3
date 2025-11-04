#include <iostream>

char readCharacter(void)
{
    char c;

    std::cout << "Please enter a character : ";
    std::cin >> c;

    return (c);
}

bool letterIsVowel(char c)
{
    c = tolower(c);

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void)
{
    if (letterIsVowel(readCharacter()))
        std::cout << "The letter is VOWEL.\n";
    else
        std::cout << "The letter is NOT vowel!\n";

    return (0);
}
