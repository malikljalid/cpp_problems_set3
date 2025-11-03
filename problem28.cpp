#include <iostream>
#include <string>
#include <cctype>

char invertCaseOf(char c)
{
    return (islower(c) ? toupper(c) : tolower(c));
}

std::string invertEntireString(std::string msg)
{
    for (int i = 0; i < (int)msg.length(); i++)
        msg[i] = invertCaseOf(msg[i]);

    return (msg);
}


int main(void)
{
    std::cout << invertEntireString("Hello WoRLd, i hate YOU!\n");

    return (0);
}
