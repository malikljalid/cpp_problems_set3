#include <iostream>
#include <string>
#include <cctype>

std::string upperEntireString(std::string msg)
{
    for (int i = 0; i < (int)msg.length(); i++)
        msg[i] = toupper(msg[i]);

    return (msg);
}

std::string lowerEntireString(std::string msg)
{
    for (int i = 0; i < (int)msg.length(); i++)
        msg[i] = tolower(msg[i]);
    
    return (msg);
}

int main(void)
{
    std::cout << upperEntireString("Hello WoRLd, i hate YOU!\n");
    std::cout << lowerEntireString("Hello WoRLd, i hate YOU!\n");
    return (0);
}
