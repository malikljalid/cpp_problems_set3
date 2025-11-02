#include <iostream>
#include <iomanip>

enum enMatrixD { ROWS=3, COLS=3 };

int getMaxNumberInMatrix(int matrix[ROWS][COLS], short int Rows, int Cols)
{
    int Max = matrix[0][0];

    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Cols; j++)
        {
            if (matrix[i][j] > Max)
                Max = matrix[i][j];
        }
    }

    return (Max);
}

int getMinNumberInMatrix(int matrix[ROWS][COLS], short int Rows, int Cols)
{
    int Min = matrix[0][0];

    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Cols; j++)
        {
            if (matrix[i][j] < Min)
                Min = matrix[i][j];
        }
    }

    return (Min);
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
    int matrix1[ROWS][COLS] = { { 9, 0, 13 }, { 6, 9, 7 }, { 1, -1, 9 } };

    printMatrix(matrix1, ROWS, COLS);

    std::cout << "Max of Matrix : " << getMaxNumberInMatrix(matrix1, ROWS, COLS) << std::endl;
    std::cout << "Min of Matrix : " << getMinNumberInMatrix(matrix1, ROWS, COLS) << std::endl;

    return (0);
}
