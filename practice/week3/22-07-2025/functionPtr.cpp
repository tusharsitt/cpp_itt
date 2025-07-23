#include <iostream>
#include <array>

#define PRINT(x) (std::cout << x << std::endl)

int add(int a, int b)
{
    return a + b;
}

int main()
{

    // array of references not allowd
    // const std::array<void (&)(), 4> arr{};
    // const std::array<int &, 4> arr2{};

    std::array<int *, 5> arr2{};

    for (int i = 0; i < 4; i++)
    {
        PRINT(arr2[i]);
    }

    int (&refToTheFunction)(int, int) = add;

    PRINT(refToTheFunction(34, 5));
}