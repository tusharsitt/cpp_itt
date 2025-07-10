#include <iostream>

union MyUnion
{

    int a;
    double b;
    char c;
    int d;
    int arr[20];
    long l;
};

int main()
{

    MyUnion u;
    // for (int i = 0; i < 20; i++)
    // {
    //     u.arr[i] = i + 23;
    // }
    u.l = 345133244232l;
    std::cout << "Size: " << sizeof(u.l) << std::endl;
    std::cout << u.b << std::endl;
    std::cout << u.a << std::endl;
    std::cout << u.c << std::endl;
    std::cout << u.d << std::endl;

    return 0;
}