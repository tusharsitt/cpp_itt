#include <iostream>

#define DEBUG
#define DEBUGG 34
int main()
{

#ifdef DEBUG
    std::cout << "I will only exist if DEBUG is defined" << std::endl;

#endif

#if defined(DEBUG) && defined(DEBUGG)
    std::cout << "I will only exist if DEBUG and DEBUGG are defined" << std::endl;

#endif

    std::cout << "I will exist" << std::endl;
}