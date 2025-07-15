#include <iostream>
#include <vector>

void printVector(std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {

        std::cout << vec.at(i);
    }
    std::cout << std::endl;
}

int main()
{

    std::vector<int> vec1{10};
    std::vector<int> vec2(10);

    printVector(vec1);
    printVector(vec2);
}