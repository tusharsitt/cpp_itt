#include <iostream>
#include <string>
#include <limits>

void printPattern(int size)
{

    int middleRow = size / 2;

    for (int row = 1; row <= size; row++)
    {

        // print upper half

        if (row <= middleRow)
        {
            for (int column = 1; column <= row; column++)
            {

                if (column % 2 != 0)
                {
                    std::cout << "1 ";
                }
                else
                    std::cout << "0 ";
            }

            for (int column = 1; column <= (size - (row * 2)); column++)
            {
                std::cout << "  ";
            }

            for (int column = 1; column <= row; column++)
            {

                if (column % 2 != 0)
                {
                    std::cout << "1 ";
                }
                else
                    std::cout << "0 ";
            }
        }

        // print lower half

        else
        {

            for (int column = 1; column <= (size - row + 1); column++)
            {
                if (size % 2 != 0 && column == middleRow + 1)
                {
                    continue;
                }

                if (column % 2 != 0)
                {
                    std::cout << "1 ";
                }
                else
                    std::cout << "0 ";
            }

            for (int column = 1; column <= (size - (2 * (size - row + 1))); column++)
            {
                std::cout << "  ";
            }

            for (int column = 1; column <= (size - row + 1); column++)
            {
                if (column % 2 != 0)
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

    std::cout << "Enter an size for the pattern: ";

    std::cin >> size;

    // Check for failed state
    while (std::cin.fail() || size < 1)
    {

        std::cout << "Enter an valid natural number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> size;
    }

    printPattern(size);
    return 0;
}