#include <iostream>

void switchFunction(int a)
{

    switch (a)
    {
    case 23:
        std::cout << "I am 23" << std::endl;
        break;

    case 24:
        std::cout << "I am 24" << std::endl;
        break;

    case 25:
        std::cout << "I am 25" << std::endl;
        break;

    case 26:
        std::cout << "I am 26" << std::endl;
        break;

    case 27:
        std::cout << "I am 27" << std::endl;
        break;

    case 28:
        std::cout << "I am 28" << std::endl;
        break;

    default:
        break;
    }
}

int main()
{

    int a = 34;
    switchFunction(a);
}