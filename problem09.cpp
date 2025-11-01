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

void printMiddleRowOfMatrix(int matrix[ROWS][COLS], short int Rows, short int Cols)
{
    short int middleRow = Rows / 2;

    std::cout << "\nMiddle Row : \n";
    for (short int i = 0; i < Cols; i++)
        std::cout << matrix[middleRow][i] << " ";
    std::cout << std::endl;
}


void printMiddleColOfMatrix(int matrix[ROWS][COLS], short int Rows, short int Cols)
{
    short int middleCol = Cols / 2;

    std::cout << "\nMiddle Col : \n";
    for (short int i = 0; i < Rows; i++)
        std::cout << "   " << std::setw(2) << matrix[i][middleCol] << std::endl;
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
    srand((unsigned int)time(NULL));
    int matrix[COLS][ROWS];

    fillMatrixWithRandomValues(matrix, ROWS, COLS);
    printMatrix(matrix, ROWS, COLS);

    printMiddleRowOfMatrix(matrix, ROWS, COLS);
    printMiddleColOfMatrix(matrix, ROWS, COLS);

    return (0);
}
