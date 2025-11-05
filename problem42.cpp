#include <iostream>
#include <string>

std::string findAndReplaceIn(std::string msg, std::string toFind, std::string toReplace)
{
    int i = msg.find(toFind);

    while (i != (int)std::string::npos)
    {
        msg.replace(i, toFind.length(), toReplace);
        i = msg.find(toFind);
    }

    return (msg);
}

int main(void)
{
    std::cout << findAndReplaceIn("Hello World i am sad so much, so much sad", "sad", "happy") << std::endl;

    return (0);
}
