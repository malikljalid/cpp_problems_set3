#include <iostream>

std::string trimRight(std::string msg)
{
    size_t end = msg.length();

    for (int i = 0; (size_t)i < end; i++)
    {
        while (msg[i] == ' ')
            i++;
        return (msg.substr(i, end - i));
    }

    return ("");
}

std::string trimLeft(std::string msg)
{
    size_t end = msg.length();

    for (int i = end - 1; (size_t)i > 0; i--)
    {
        while (msg[i] == ' ')
            i--;
        return (msg.substr(0, i + 1));
    }

    return ("");
}

std::string trimAll(std::string msg)
{
    return (trimLeft(trimRight(msg)));
}

int main(void)
{
    std::string msg = "     Hello World 2025      ";

    std::cout << msg << std::endl;
    std::cout << trimRight(msg) << std::endl;
    std::cout << trimLeft(msg) << std::endl;
    std::cout << trimAll(msg) << std::endl;

    return (0);
}
