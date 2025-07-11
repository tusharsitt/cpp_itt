#include <iostream>
#include <array>

struct House
{
    int flatNo{};
    int roomCount{};
};

int main()
{

    std::array<House, 3> arr{
        {{33, 4},
         {34, 5},
         {36, 2}}};
}