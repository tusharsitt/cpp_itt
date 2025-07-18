#include <iostream>
int gettingFromOtherFile = 42;
static int thisWillnotExtern = 43;
void printing()
{
    std::cout << "I am printing" << std::endl;
}