#include <iostream>

int main()
{

    int a{};

    std::cout << a << std::endl;

    ++a = 34;

    std::cout << a << std::endl;

    a = 0;
    // this will return in a rvalue assignment, which is not allowed
    // a++ = 3;

    int temp = a++;

    std::cout << temp << std::endl;
    std::cout << a << std::endl;

    double dd = 34.5;

    int *ptr = (int *)&dd;

    int ii = 43;
    double *dptr = (double *)&ii;

    std::cout << ptr << std::endl;
    std::cout << &dd << std::endl;

    std::cout << sizeof(*dptr) << std::endl;
    std::cout << sizeof(ii) << std::endl;

    int in = 936;
    float *fptr = (float *)&in;

    std::cout << *fptr << std::endl;

    int iii = 55;
    uint32_t *bitptr = (uint32_t *)&iii;
    std::cout << *bitptr << std::endl;
}