#include <iostream>
#include <array>

struct House
{
    int flatNo{};
    int roomCount{};
};

void printStruct(House *h)
{
    std::cout << h->flatNo << " " << h->roomCount << std::endl;
}

int main()
{

    House house{23, 5};
    printStruct(&house);

    std::array<House, 2> arr3{
        {23, 5, 4, 345}};

    for (int i = 0; i < 2; i++)
    {
        printStruct(&arr3[i]);
    }

    std::array<House, 3> arr{

        {{

         },
         {

         },
         {

         }}

    };

    std::array<House, 3> arr2 = {House{22, 3}, House{34, 6}, House{34, 5}};
}