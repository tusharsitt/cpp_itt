#include <iostream>

#define D 23
#define C good

int main()
{

#ifdef D
    std::cout << "Bla bla \n";
#endif

#if C
    std::cout << "Bla bla \n";
#endif

#if 4 > 34
    std::cout << "FOO foo \n";
#endif
}