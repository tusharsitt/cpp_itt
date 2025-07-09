#include <iostream>
#include <string>
#include <limits>

void printPattern(int size)
{

    int middleRow = size / 2;

    for (int row = 0; row < size; row++)
    {

        if (row < middleRow)
        {

            for (int column = 0; column <= row; column++)
            {

                if (column % 2 == 0)
                {
                    std::cout << "1 ";
                }
                else
                    std::cout << "0 ";

                // if(column != row) std::cout <;
            }

            for (int column = 0; column < (size - (row * 2) - 2); column++)
            {
                std::cout << "  ";
            }

            for (int column = 0; column <= row; column++)
            {

                if (column % 2 == 0)
                {
                    std::cout << "1 ";
                }
                else
                    std::cout << "0 ";
            }
        }

        else if (row == middleRow)
        {
            for (int column = 0; column < size; column++)
            {
                if (column % 2 == 0)
                {
                    std::cout << "1 ";
                }
                else
                    std::cout << "0 ";
            }
        }

        else
        {

            for (int column = 0; column < (size - row); column++)
            {
                if (column % 2 == 0)
                {
                    std::cout << "1 ";
                }
                else
                    std::cout << "0 ";
            }

            for (int column = 0; column <= (middleRow - (size - row)) * 2; column++)
            {
                std::cout << "  ";
            }

            for (int column = 0; column < (size - row); column++)
            {
                if (column % 2 == 0)
                {
                    std::cout << "1 ";
                }
                else
                    std::cout << "0 ";
            }
        }

        std::cout << '\n';
    }
}

int main()
{

    int size{};

    std::cout << "Enter an odd whole size for the pattern: " << '\n';

    std::cin >> size;

    // Check for failed state and even integer
    while (std::cin.fail() || size % 2 == 0)
    {

        std::cout << "Enter an valid odd whole number: " << '\n';
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> size;
    }

    printPattern(size);
    return 0;
}