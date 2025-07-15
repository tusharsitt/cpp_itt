#include <iostream>
#include <array>

// c-style array is getting decayed, so the original will get modified here.
void printArray(int arr[10])
{
    for (int i = 0; i < 10; i++)
    {
        arr[i] += 2;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printStdArray(std::array<int, 3> arr)
{

    for (int i = 0; i < 3; i++)
    {
        arr[i] += 2;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{

    int arr[10]{};
    printArray(arr);

    std::array<int, 3> arr2{23, 5, 7};

    printStdArray(arr2);

    for (int i = 0; i < 3; i++)
    {

        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::cout << arr[i] << " ";
    }
}