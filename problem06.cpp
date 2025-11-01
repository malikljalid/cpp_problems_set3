#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

enum enMatrixD { ROWS=3, COLS=3 };

void fillMatrixWithOrderedNumbers(int matrix[ROWS][COLS], int Rows, int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
            matrix[i][j] = ((i + 1) * i) + (j + 1);
    }
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

    int matrix[ROWS][COLS];

    fillMatrixWithOrderedNumbers(matrix, ROWS, COLS);
    printMatrix(matrix, ROWS, COLS);

    return (0);
}
