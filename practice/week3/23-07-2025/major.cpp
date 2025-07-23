#include <iostream>

int main()
{

    int rows = 3;
    int cols = 2;

    int *matrix = new int[rows * cols]{23, 45, 6, 8, 5, 0};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[j * rows + i] << " ";
        }
        std::cout << "\n";
    }
}