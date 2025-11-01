#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

enum enMatrixD { ROWS=3, COLS=3 };

short int randomNumber(short int From, short int To)
{
    return ((rand() % (To - From + 1)) + From);
}

void fillMatrixWithRandomValues(int matrix[ROWS][COLS], short int Rows, short int Cols)
{
    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Cols; j++)
            matrix[i][j] = randomNumber(1, 100);
    }
}

void printSumOfColsOfMatrix(int matrix[ROWS][COLS], short int Rows, short int Cols)
{
    short int SumOfCol[COLS] = { 0 };

    std::cout << "\nThe following is the sum of each row in the matrix : \n";

    for (short int i = 0; i < ROWS; i++)
    {
        for (short int j = 0; j < COLS; j++)
            SumOfCol[j] += matrix[i][j];
    }

    for (short int i = 0; i < COLS; i++)
        std::cout << "Col " << i << " Sum = " << SumOfCol[i] << std::endl;
}

void printMatrix(int matrix[ROWS][COLS], short int Rows, short int Cols)
{
    std::cout << "The Following is a " << Rows << 'x' << Cols << " Matrix : \n";

    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Cols; j++)
            std::cout << std::setw(3) << matrix[i][j] << "      ";
        std::cout << std::endl;
    }
}

int main(void)
{
    srand((unsigned int)time(NULL));
    int matrix[COLS][ROWS];

    fillMatrixWithRandomValues(matrix, ROWS, COLS);
    printMatrix(matrix, ROWS, COLS);

    printSumOfColsOfMatrix(matrix, ROWS, COLS);
    return (0);
}
