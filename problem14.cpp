#include <iostream>
#include <iomanip>

enum enMatrixD { ROWS=3, COLS=3 };

bool matrixIsScalar(int matrix[ROWS][COLS], short int Rows, int Cols)
{
    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Cols; j++)
        {
            if (i != j && matrix[i][j] != 0)
                return (false);
            if (i == j && matrix[i][j] != matrix[0][0])
                return (false);
        }
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
    int matrix1[ROWS][COLS] = { { 9, 0, 0 }, { 0, 9, 0 }, { 0, 0, 9 } };

    if (matrixIsScalar(matrix1, ROWS, COLS))
        std::cout << "Matrix is Scalar !\n";
    else
        std::cout << "Matrix is NOT Scalar!\n";

    return (0);
}
