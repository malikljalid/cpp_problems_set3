#include <iostream>
#include <iomanip>

enum enMatrixD { ROWS=3, COLS=3 };

int  getSumOfMatrixValues(int matrix[ROWS][COLS], short int Rows, short int Cols)
{
    short int Sum = 0;

    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Cols; j++)
            Sum += matrix[i][j];
    }

    return (Sum);
}

bool matrixesAreEqual(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], short int Rows, short int Cols)
{
    return (getSumOfMatrixValues(matrix1, Rows, Cols) == getSumOfMatrixValues(matrix2, Rows, Cols));
}

int main(void)
{
    int matrix1[ROWS][COLS] = { { 1, 3, 7 }, { 8, 2, 6 }, { 5, 9, 4 } };
    int matrix2[ROWS][COLS] = { { 9, 8, 7 }, { 3, 4, 5 }, { 6, 1, 2 } };

    if (matrixesAreEqual(matrix1, matrix2, ROWS, COLS))
        std::cout << "Matrixes are equal !\n";
    else
        std::cout << "Matrixes are NOT equal!\n";

    return (0);
}
