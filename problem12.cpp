#include <iostream>
#include <iomanip>

enum enMatrixD { ROWS=3, COLS=3 };

bool matrixesAreTypical(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], short int Rows, short int Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
                return (false);
        }
    }

    return (true);
}

int main(void)
{
    int matrix1[ROWS][COLS] = { { 1, 3, 7 }, { 8, 2, 6 }, { 5, 9, 4 } };
    int matrix2[ROWS][COLS] = { { 1, 3, 7 }, { 8, 2, 6 }, { 5, 9, 4 } };

    if (matrixesAreTypical(matrix1, matrix2, ROWS, COLS))
        std::cout << "Matrixes are TYPICAL !\n";
    else
        std::cout << "Matrixes are NOT typical!\n";

    return (0);
}
