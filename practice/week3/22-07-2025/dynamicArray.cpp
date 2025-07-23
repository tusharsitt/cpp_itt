#include <iostream>

#define parray(A, L)              \
    for (i = 0; i < L; i++)       \
    {                             \
        std::cout << A[i] << " "; \
        if (i == L - 1)           \
            std::cout << '\n';    \
    }

using funcPtr = int (*)(int, int);

int main()
{
    int i{0};
    int *arr{new int[10]};

    int *arrWithInit{new int[10]{43, 5, 6, 3, 62, 63, 622, 332, 5}};

    arr[3] = 54543;
    parray(arr, 10);
    parray(arrWithInit, 10);

    // array of pointers
    int **arr3{new int *[10]};
    parray(arr3, 10);

    const int *constArray{new int[10]};
    // can't update
    // constArray[8] = 78;
    parray(constArray, 10);

    funcPtr *arrayOfFunctionPtr{new funcPtr[10]};
    parray(arrayOfFunctionPtr, 10);

    delete[] arr;
    delete[] arr3;
    delete[] arrWithInit;
    delete[] constArray;
    delete[] arrayOfFunctionPtr;

    return 0;
}