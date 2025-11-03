#include <iostream>

int fibonnaciLoop(int Number)
{
    int i = 0;
    int N1 = 0;
    int N2 = 1;
    int fibonnaci = 1;

    for (i = 0; i < Number; i++)
    {
        std::cout << fibonnaci << " ";

        fibonnaci = N1 + N2;
        N1 = N2;
        N2 = fibonnaci;
    }

    std::cout << std::endl;

    return (fibonnaci);
}

int main(void)
{
    fibonnaciLoop(10);
    return (0);
}
