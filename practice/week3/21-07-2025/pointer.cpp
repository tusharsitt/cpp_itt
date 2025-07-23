#include <iostream>
#include <string>

#define PRINT(x) (std::cout << x << std::endl)

int main()
{

    int a = 43;
    int *ptr = &a;

    int *wildPointer;

    std::string s = "3434";
    const double &dref = a;

    PRINT(ptr);
    PRINT(wildPointer);

    std::cout << typeid(wildPointer).name() << std::endl;

    // this will case the prg to crash, as derefrencing wild pointer, causes seg fault
    // PRINT(*wildPointer);

    int *&refToPointer = ptr;
    const int &refToDerefPointer = *ptr;
    PRINT(refToPointer);
    PRINT(*refToPointer);

    PRINT(refToDerefPointer);

    int *newVar = new int(10);
    delete newVar;
    // defrence of dangling ptr results in garbage value
    PRINT(*newVar);

    int *nullPointer = nullptr;
    // nullptr address is always zero
    PRINT(nullPointer);
    // defrence of nullptr returns in crash
    // PRINT(*nullPointer);

    // std::nullptr_t is implicity converted to any type it is being pointed by,
    // but you can't do the other way around.
    // int *intPtr = (std::nullptr_t)&a;

    // cant point to literal,
    // int *const constantPtr{678};
    // but you can do like this
    const int &constantReftoLiteral = 54;
    const int *pppp = &constantReftoLiteral;
}