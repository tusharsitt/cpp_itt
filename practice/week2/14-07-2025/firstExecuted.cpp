#include <iostream>

int getGlobal()
{
    std::cout << "I will run even before the main function" << std::endl;
    return 10;
}
int globalVaribale{getGlobal()};

int main()
{

    std::cout << "Hello, main mai aap ka sawagat hai!!!" << std::endl;
    return 0;
}