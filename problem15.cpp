#include <iostream>
#include <iomanip>

enum enMatrixD { ROWS=3, COLS=3 };

int getNumberOccuranceInMatrix(int Number, int matrix[ROWS][COLS], short int Rows, int Cols)
{
    int count = 0;

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
    int matrix1[ROWS][COLS] = { { 9, 0, 9 }, { 6, 9, 7 }, { 1, 0, 9 } };

    printMatrix(matrix1, ROWS, COLS);

    std::cout << "\nNumber 9 appear " << getNumberOccuranceInMatrix(9, matrix1, ROWS, COLS) << " times in matrix.\n";

    return (0);
}
