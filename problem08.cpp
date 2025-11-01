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
            matrix[i][j] = randomNumber(1, 9);
    }
}

void multiplyTwoMatrixes(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], int matrixRes[ROWS][COLS], short int Rows, short int Cols)
{
    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Rows; j++)
            matrix3[i][j] = matrix1[i][j] * matrix2[i][j];
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

    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];
    int matrixRes[ROWS][COLS];

    fillMatrixWithRandomValues(matrix1, ROWS, COLS);
    printMatrix(matrix1, ROWS, COLS);

    fillMatrixWithRandomValues(matrix2, ROWS, COLS);
    printMatrix(matrix2, ROWS, COLS);

    multiplyTwoMatrixes(matrix1, matrix2, matrixRes, ROWS, COLS);
    printMatrix(matrixRes, ROWS, COLS);

    return (0);
}
