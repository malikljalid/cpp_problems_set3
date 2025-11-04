#include <iostream>
#include <string>

void printEachWordInString(std::string msg)
{
    int end = (int)msg.length();

    for (int i = 0; i < end; i++)
    {
        while (msg[i] != ' ' && i < end)
            std::cout << msg[i++];
        
        while (msg[i] == ' ' && i < end)
            i++;
        std::cout << std::endl;
        i--;
    }
}

int main(void)
{
    printEachWordInString("   Hello world,    hozza going  !!  \n");
    return (0);
}
