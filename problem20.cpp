#include <iostream>
#include <iomanip>

enum enMatrixD { ROWS=3, COLS=3 };

bool rowIsPalindorme(int row[COLS], short int Cols)
{
    for (short int i = 0; i < Cols / 2; i++)
    {
        if (row[i] != row[Cols - i - 1])
            return (false);
    }

    return (true);
}

bool matrixIsPalindorme(int matrix[ROWS][COLS], short int Rows, short int Cols)
{
    for (int short i = 0; i < Rows; i++)
    {
        if (rowIsPalindorme(matrix[i], Cols) == false)
            return (false);
    }

    return (true);
}

void printMatrix(int matrix[ROWS][COLS], short int Rows, short int Cols)
{
    std::cout << "The Following is a " << Rows << "x" << Cols << " Matrix : \n";

    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Cols; j++)
            std::cout << std::setw(3) << matrix[i][j] << "      ";
        std::cout << std::endl;
    }
}

int main(void)
{
    int matrix1[ROWS][COLS] = { { 9, 0, 9 }, { 6, 9, 6 }, { 1, -1, 1 } };

    printMatrix(matrix1, ROWS, COLS);

    if (matrixIsPalindorme(matrix1, ROWS, COLS))
        std::cout << "Matrix is PALINDORME! \n";
    else
        std::cout << "Matrix is NOT palindorme. \n"; 

    return (0);
}
