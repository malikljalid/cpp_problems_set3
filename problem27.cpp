#include <iostream>

char readCharacter(void)
{
    char c;

    std::cout << "Please enter a character : ";
    std::cin >> c;

    return (c);
}

char invertCaseOf(char c)
{
    return (islower(c) ? toupper(c) : tolower(c));
}

int main(void)
{
    std::cout << "Character after invert case : " << invertCaseOf(readCharacter()) << std::endl;
    return (0);
}
