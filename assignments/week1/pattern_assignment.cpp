#include <iostream>
#include <limits>

void printAlternatingPattern(int count, int skipColumn)
{

    for (int column = 1; column <= count; column++)
    {

        if (column == skipColumn)
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
}

void printSpaces(int count)
{
    for (int column = 1; column <= count; column++)
    {
        std::cout << "  ";
    }
}

void printPattern(int size)
{

    int middleRow = size / 2;

    for (int row = 1; row <= size; row++)
    {

        // print upper half

        if (row <= middleRow)
        {

            printAlternatingPattern(row, -1);

            printSpaces(size - (row * 2));

            printAlternatingPattern(row, -1);
        }

        // print lower half

        else
        {

            int skipColumn = -1;
            if (size % 2 != 0)
            {
                skipColumn = middleRow + 1;
            }
            printAlternatingPattern(size - row + 1, skipColumn);

            printSpaces(size - (2 * (size - row + 1)));

            printAlternatingPattern(size - row + 1, -1);
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