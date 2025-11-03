#include <iostream>

int fibonnaciSerie(int Number)
{
    if (Number == 0)
        return (0);
    if (Number == 1)
        return (1);
    return (fibonnaciSerie(Number-1) + fibonnaciSerie(Number-2));
}

int main(void)
{
    for (int i = 0; i <= 10; i++)
        std::cout << fibonnaciSerie(i) << " ";
    std::cout << std::endl;

    return (0);
}
