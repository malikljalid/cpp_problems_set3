#include <iostream>
#include <string>

char invertCaseOf(char c)
{
    return (islower(c) ? toupper(c) : tolower(c));
}

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

int getLetterOccuranceInString(char c, std::string msg)
{
    int occ = 0;

    for (std::string::iterator i = msg.begin(); i < msg.end(); i++)
    {
        if (*i == c || *i == invertCaseOf(c))
            occ++;
    }

    return (occ);
}

int getCountOf(char c, std::string msg, bool matchCase = true)
{
    if (matchCase)
        return (getCharacterOccuranceInString(c, msg));
    else
        return (getLetterOccuranceInString(c, msg));
}

int main(void)
{
    std::cout << "z has repeated " << getCountOf('z', "hello Zakaria, howzza going wiz U?\n", true) << std::endl;
    std::cout << "z has repeated " << getCountOf('z', "hello Zakaria, howzza going wiz U?\n", false) << std::endl;
    std::cout << "z has repeated " << getCountOf('z', "hello Zakaria, howzza going wiz U?\n") << std::endl;

    return (0);
}
