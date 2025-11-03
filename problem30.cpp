#include <iostream>
#include <string>

int getCharacterOccuranceInString(char c, std::string msg)
{
    int occ = 0;

    for (int i = 0; (size_t)i < msg.length(); i++)
    {
        if (msg[i] == c)
            occ++;
    }

    return (occ);
}

int main(void)
{
    std::cout << "z has repeated " << getCharacterOccuranceInString('z', "hello zakaria, howzza going with U?\n") << std::endl;

    return (0);
}
