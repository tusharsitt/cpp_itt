#include <iostream>
#include <array>

using std::endl;

void printArray(std::array<int, 5> &arr)
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{

    std::array<int, 5> arrayDefautInit;  // garbage value for elements
    std::array<int, 5> arrayValueInit{}; // value-init for elements

    std::array<int, 5> arrayCopyInit = {2, 5, 6, 4, 7}; // copy init
    std::array<int, 5> arrayListInit{23, 6, 34, 56, 4}; // list init

    // getting length: .size() -> give "size_type" as return, which is constexpr also
    // cause std::array size needs to be determined at compile time
    std::cout << "size is: " << arrayCopyInit.size() << std::endl;

    // getting elements
    std::cout << arrayCopyInit[3] << endl;
    // no error: just give value at that memory location
    std::cout << arrayCopyInit[9] << endl;
    std::cout << arrayCopyInit.at(3) << endl;
    // error: give error at runtime, but compiles fine
    std::cout << arrayCopyInit.at(9) << endl;
    std::cout << std::get<3>(arrayCopyInit) << endl;
    // error: gives error at compile time only
    // We can check for bound error at compile time for std::array
    // only cause its size is fixed and known at compiletime, but do same
    // for std::vector
    std::cout << std::get<9>(arrayCopyInit) << endl;

    printArray(arrayDefautInit);
    printArray(arrayValueInit);
    printArray(arrayCopyInit);
    printArray(arrayListInit);
}