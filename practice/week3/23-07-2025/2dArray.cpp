#include <iostream>

void printMat(int **arr, int l, int b)
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

    int n = 43;

    int **arr = new int *[3]{};

    int *arrr = new int[n];

    for (int i = 0; i < 3; i++)
    {

        *(arr + i) = new int[4]{};
    }

    std::cout << arr << std::endl;
    std::cout << *arr << std::endl;
    std::cout << **arr << std::endl;

    for (int i = 0; i < 3; i++)
    {
        std::cout << *(arr + i) << " ";
    }
    std::cout << std::endl;

    printMat(arr, 3, 4);

    return 0;
}