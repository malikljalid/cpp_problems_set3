#include <iostream>
#include <iomanip>

enum enMatrixD { ROWS=3, COLS=3 };

short int readNumber(void)
{
    short int Number;

    std::cout << "\nPlease enter a number to search for : ";
    std::cin >> Number;

    return (Number);
}

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

bool elemExistInMatrix(int elem, int matrix[ROWS][COLS], short int Rows, short int Cols)
{
    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Cols; j++)
        {
            if (matrix[i][j] == elem)
                return (true);
        }
    }

    return (false);
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
    int matrix1[ROWS][COLS];

    fillMatrixWithRandomValues(matrix1, ROWS, COLS);
    printMatrix(matrix1, ROWS, COLS);

    if (elemExistInMatrix(readNumber(), matrix1, ROWS, COLS))
        std::cout << "Number EXIST int matrix !\n";
    else
        std::cout << "Number does NOT exist in matrix !\n";

    return (0);
}
