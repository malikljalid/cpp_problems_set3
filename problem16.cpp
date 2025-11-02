#include <iostream>
#include <iomanip>

enum enMatrixD { ROWS=3, COLS=3 };

short int getNumberOccuranceInMatrix(int Number, int matrix[ROWS][COLS], short int Rows, int Cols)
{
    short int count = 0;

    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Cols; j++)
        {
            if (matrix[i][j] == Number)
                count++;
        }
    }

    return (count);
}

bool matrixIsSparce(int matrix[ROWS][COLS], short int Rows, short int Cols)
{
    short int zeros         = getNumberOccuranceInMatrix(0, matrix, Rows, Cols);
    short int matrixSize    = Rows * Cols;

    return (zeros > matrixSize / 2);
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
    int matrix1[ROWS][COLS] = { { 9, 0, 0 }, { 0, 0, 9 }, { 1, 0, 9 } };

    printMatrix(matrix1, ROWS, COLS);

    if (matrixIsSparce(matrix1, ROWS, COLS))
        std::cout << "Matrix is SPARCE !\n";
    else
        std::cout << "Matrix is NOT sparce !\n";

    return (0);
}
