#include <iostream>
#include <string>

void printUpperAndLowerCharactersCountInString(std::string msg)
{
    int upper = 0;
    int lower = 0;

    for (int i = 0; (size_t)i < msg.length(); i++)
    {
        if (isupper(msg[i]))
            upper++;
        if (islower(msg[i]))
            lower++;
    }

    std::cout << "String length        : " << msg.length() << std::endl;
    std::cout << "Capital letter count : " << upper << std::endl;
    std::cout << "Small letter count   : " << lower << std::endl;
}

int main(void)
{
    std::string msg = "Hello worlD!\n";

    std::cout << msg << std::endl;
    printUpperAndLowerCharactersCountInString(msg);

    return (0);
}
