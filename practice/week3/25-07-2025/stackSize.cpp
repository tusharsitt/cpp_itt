#include <iostream>

void checkStackDepth(int n, int *mainN)
{
    int current;
    std::cout << "Call no:" << n
              << " stack size used:" << (&current - mainN) * sizeof(int)
              << " bytes" << std::endl;
    checkStackDepth(n + 1, mainN);
}

int main()
{
    int n;
    checkStackDepth(1, &n);
}
