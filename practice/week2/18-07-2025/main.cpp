#include <iostream>

extern int gettingFromOtherFile;
// extern int thisWillnotExtern;
void printing();

int main()
{
    std::cout << "gettingFromOtherFile: " << gettingFromOtherFile << "\n";
    // std::cout << "thisWillnotExtern: " << thisWillnotExtern << "\n";
    printing();
    return 0;
}