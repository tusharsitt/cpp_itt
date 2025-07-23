#include <iostream>

#define PRINT(X) (std::cout << X << std::endl)

int main()
{

    int *ptr{new int{67}};

    // this double delete works here, cause second time we are delete nullptr
    // which is allowed, but we dont set ptr to nullptr and delete is two times
    // it will throw : "free(): double free detected in tcache 2"
    delete ptr;
    ptr = nullptr;

    delete ptr;

    PRINT(ptr);
}