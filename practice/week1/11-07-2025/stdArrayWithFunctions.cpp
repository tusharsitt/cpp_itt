#include <iostream>
#include <array>

void returningArrayByOutParam(std::array<int, 6> &arr)
{

    for (int i = 0; i < 6; i++)
    {
        arr[i] = i + 4;
    }
}

int main()
{

    std::array<int, 6> array{};
    returningArrayByOutParam(array);
}