#include <iostream>
#include <iomanip>

enum enMatrixD { ROWS=3, COLS=3 };

// normal solution.. working but slower
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

void printIntersectedElementsInTwoMatrixes(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], short int Rows, short int Cols)
{
    std::cout << "Intersected elements are : ";

    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Cols; j++)
        {
            if (elemExistInMatrix(matrix1[i][j], matrix2, Rows, Cols))
                std::cout << matrix1[i][j] << " ";
        }
    }

    std::cout << std::endl;
}
// ----------------------------------------


// --------  efficent solution  -----------
bool elemExistInList(int elem, int list[ROWS * COLS], short int listSize)
{
    for (short int i = 0; i < listSize; i++)
    {
        if (list[i] == elem)
            return (true);
    }

    return (false);
}

void addElemToList(int elem, int list[ROWS * COLS], short int &listSize)
{
    list[listSize++] = elem;
}

void listOfMatrixElements( int list[ROWS * COLS], short int &listSize, int matrix[ROWS][COLS], short int Rows, short int Cols)
{
    for (short int i = 0; i < Rows; i++)
    {
        for (short int j = 0; j < Cols; j++)
        {
            if (elemExistInList(matrix[i][j], list, listSize) == false)
                addElemToList(matrix[i][j], list, listSize);
        }
    }
}

void _printIntersectedElementsInTwoMatrixes(int matrix1[ROWS][COLS], int matrix2[ROWS][COLS], short int Rows, short int Cols)
{
    int list1[ROWS * COLS] = { 0 };
    int list2[ROWS * COLS] = { 0 };
    short int listSize1 = 0;
    short int listSize2 = 0;

    listOfMatrixElements(list1, listSize1, matrix1, Rows, Cols);
    listOfMatrixElements(list2, listSize2, matrix2, Rows, Cols);

    std::cout << "Intersected elements are : ";

    for (int i = 0; i < listSize1; i++)
    {
        if (elemExistInList(list1[i], list2, listSize2))
            std::cout << list1[i] << " ";
    }

    std::cout << std::endl;
}
// ----------------------------------------


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
    int matrix1[ROWS][COLS] = { { 1, 3, 7 }, { 8, 2, 6 }, { 5, 9, 4 } };
    int matrix2[ROWS][COLS] = { { 0, 20, 7 }, { 66, 2, 9 }, { 10, 9, 4 } };

    printMatrix(matrix1, ROWS, COLS);
    printMatrix(matrix2, ROWS, COLS);

    printIntersectedElementsInTwoMatrixes(matrix1, matrix2, ROWS, COLS);
    _printIntersectedElementsInTwoMatrixes(matrix1, matrix2, ROWS, COLS);

    return (0);
}
