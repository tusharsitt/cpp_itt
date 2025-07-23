#include <iostream>
#include <limits>
#include "matrixUtil.h"

void clearBuffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int inputOperationCode()
{

    int opCode{0};
    std::cout << "Select the operation to perform:" << '\n';
    std::cout << "1. Matrix Addition" << '\n';
    std::cout << "2. Matrix Multiplication" << '\n';
    std::cout << "Enter your choice (1/2): ";

    std::cin >> opCode;

    while (std::cin.fail() || std::cin.peek() != '\n' || (opCode < 1 || opCode > 2))
    {

        clearBuffer();
        std::cout << "Enter the valid choice(1/2): ";
        std::cin >> opCode;
    }

    return opCode;
}

void inputMatrixDimension(Matrix &matrix)
{

    std::cin >> matrix.tRow >> matrix.tColumn;

    while (std::cin.fail() || std::cin.peek() != '\n' || matrix.tColumn < 1 || matrix.tRow < 1)
    {

        clearBuffer();
        std::cout << "Enter valid positive dimensions. (eg, 3x2 -> 3 2): ";
        std::cin >> matrix.tRow >> matrix.tColumn;
    }
}

bool validDimensionsForOp(Matrix &m1, Matrix &m2, int opCode)
{
    bool isValid{true};

    if (opCode == 1)
        isValid = ((m1.tRow == m2.tRow) && (m1.tColumn == m2.tColumn));
    else
        isValid = (m1.tColumn == m2.tRow);

    if (!isValid)
        std::cout << "Given dimensions for the matrices dont follow op rules, try again" << '\n';

    return isValid;
}

bool inputMatrixElement(Matrix &matrixRef)
{

    for (int row = 0; row < matrixRef.tRow; row++)
    {
        for (int column = 0; column < matrixRef.tColumn; column++)
        {
            std::cin >> matrixRef.matrix[row][column];
            if (std::cin.fail())
            {
                clearBuffer();
                std::cout << "Enter only valid double values, start again." << '\n';
                return false;
            }
        }
    }
    return true;
}

void getMatrixInput(Matrix &matrixRef)
{
    allocateMatrixMemory(matrixRef);

    std::cout << "Enter input for " << matrixRef.tRow << " x " << matrixRef.tColumn << " matrix: ";
    bool inputTaken = inputMatrixElement(matrixRef);

    while (!inputTaken)
    {
        std::cout << "Enter input for " << matrixRef.tRow << " x " << matrixRef.tColumn << " matrix: ";
        inputTaken = inputMatrixElement(matrixRef);
    }
    clearBuffer();
}

int main()
{

    std::cout << "You are in matrix now:" << '\n';
    int opCode = inputOperationCode();

    Matrix m1;
    Matrix m2;

    do
    {
        std::cout << "Enter dimensions for first matrix. (eg, 3x2 -> 3 2): ";
        inputMatrixDimension(m1);
        std::cout << "Enter dimensions for second matrix. (eg, 3x2 -> 3 2): ";
        inputMatrixDimension(m2);

    } while (!validDimensionsForOp(m1, m2, opCode));

    getMatrixInput(m1);
    getMatrixInput(m2);

    Matrix result;

    bool isSuccess{true};

    if (opCode == 1)
        isSuccess = addMatrices(result, m1, m2);
    else
        isSuccess = multiplyMatrices(result, m1, m2);

    if (isSuccess)
        printMatrix(result);
    else
        std::cout << "Operation Failed \n";

    deallocateMatrixMemory(m1);
    deallocateMatrixMemory(m2);
    deallocateMatrixMemory(result);
}