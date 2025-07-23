#include <iostream>

void printMat(int (*arr)[3], int l, int b)
{

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < b; j++)
        {

            std::cout << *(*(arr + i) + j) << " ";
        }
        std::cout << '\n';
    }
}

int main()
{
    int l = 3;

    int (*ptr)[3] = new int[3][3]{1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << ptr << std::endl;
    std::cout << ptr + 1 << std::endl;

    std::cout << *ptr << std::endl;
    std::cout << *(ptr + 1) << std::endl;
    std::cout << **ptr << std::endl;

    std::cout << *ptr + 1 << std::endl;
    std::cout << *(*ptr + 1) << std::endl;

    printMat(ptr, 3, 3);
}