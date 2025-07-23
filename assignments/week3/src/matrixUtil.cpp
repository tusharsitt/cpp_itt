#include <iostream>
#include "matrixUtil.h"

void printMatrix(Matrix &matrixRef)
{

    if (matrixRef.matrix == nullptr)
    {
        std::cout << "Matrix doesn't exist.\n";
        return;
    }

    for (int row = 0; row < matrixRef.tRow; row++)
    {
        for (int column = 0; column < matrixRef.tColumn; column++)
        {
            std::cout << matrixRef.matrix[row][column] << " ";
        }
        std::cout << '\n';
    }
}

bool allocateMatrixMemory(Matrix &matrixRef)
{
    matrixRef.matrix = new (std::nothrow) double *[matrixRef.tRow] {};

    if (matrixRef.matrix == nullptr)
    {
        std::cout << "Error in memory allocation. \n";
        return false;
    }

    for (int row = 0; row < matrixRef.tRow; row++)
    {
        matrixRef.matrix[row] = new (std::nothrow) double[matrixRef.tColumn]{};
        if (matrixRef.matrix[row] == nullptr)
        {
            std::cout << "Error in memory allocation. \n";
            deallocateMatrixMemory(matrixRef);
            return false;
        }
    }

    return true;
}

void deallocateMatrixMemory(Matrix &matrixRef)
{
    if (matrixRef.matrix != nullptr)
    {
        for (int row = 0; row < matrixRef.tRow; row++)
        {
            delete[] matrixRef.matrix[row];
        }
        delete[] matrixRef.matrix;
        matrixRef.matrix = nullptr;
    }
}

bool addMatrices(Matrix &resultMatrix, Matrix &m1, Matrix &m2)
{
    resultMatrix.tColumn = m1.tColumn;
    resultMatrix.tRow = m1.tRow;

    bool isAllocated = allocateMatrixMemory(resultMatrix);
    if (!isAllocated)
        return false;

    for (int row = 0; row < resultMatrix.tRow; row++)
    {
        for (int column = 0; column < resultMatrix.tColumn; column++)
        {
            resultMatrix.matrix[row][column] = m1.matrix[row][column] + m2.matrix[row][column];
        }
    }

    return true;
}

bool multiplyMatrices(Matrix &resultMatrix, Matrix &m1, Matrix &m2)
{

    resultMatrix.tRow = m1.tRow;
    resultMatrix.tColumn = m2.tColumn;

    bool isAllocated = allocateMatrixMemory(resultMatrix);
    if (!isAllocated)
        return false;

    for (int row = 0; row < resultMatrix.tRow; row++)
    {
        for (int column = 0; column < resultMatrix.tColumn; column++)
        {
            for (int common = 0; common < m2.tRow; common++)
            {
                resultMatrix.matrix[row][column] += m1.matrix[row][common] * m2.matrix[common][column];
            }
        }
    }
    return true;
}