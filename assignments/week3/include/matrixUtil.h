#ifndef MATRIX_UTIL_H
#define MATRIX_UTIL_H

struct Matrix
{
    int tRow{0};
    int tColumn{0};
    double **matrix{nullptr};
};

bool addMatrices(Matrix &resultMatrix, Matrix &m1, Matrix &m2);
bool multiplyMatrices(Matrix &resultMatrix, Matrix &m1, Matrix &m2);
bool allocateMatrixMemory(Matrix &matrix);
void printMatrix(Matrix &matrixRef);
void deallocateMatrixMemory(Matrix &matrix);

#endif
