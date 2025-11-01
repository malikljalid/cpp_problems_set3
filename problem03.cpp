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

void calculateSumOfRowsOfMatrix(int matrix[ROWS][COLS], int SumOfRow[ROWS], short int Rows, short int Cols)
{
    for (short int i = 0; i < ROWS; i++)
    {
        for (short int j = 0; j < COLS; j++)
            SumOfRow[i] += matrix[i][j];
    }
}

void printMatrixSumOfRows(int SumOfMatrixRows[ROWS], int Rows)
{
    std::cout << "\nThe following is the sum of each row in the matrix : \n";

    for (int i = 0; i < ROWS; i++)
        std::cout << "Row " << i << " Sum = " << SumOfMatrixRows[i] << std::endl;
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
    int SumOfMatrixRows[ROWS] = { 0 };

    fillMatrixWithRandomValues(matrix, ROWS, COLS);
    printMatrix(matrix, ROWS, COLS);

    calculateSumOfRowsOfMatrix(matrix, SumOfMatrixRows, ROWS, COLS);
    printMatrixSumOfRows(SumOfMatrixRows, ROWS);

    return (0);
}
