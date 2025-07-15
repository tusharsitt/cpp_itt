#include <iostream>

int add(int, int);
namespace addSpace
{
    int add(int, int);
}

int main()
{

    int a{34};
    int b{8};

    std::cout << add(a, b) << std::endl;
    std::cout << addSpace::add(23, 5) << std::endl;
}