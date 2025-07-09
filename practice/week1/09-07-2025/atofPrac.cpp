#include <iostream>
#include <cstdlib>
#include <string>

int main()
{

    std::string s;

    std::cin >> s;
    // since atof is taken from c, and c works with strings defined as char array
    // so convert the string type to c style string using c_str() defind in string lib

    std::cout << std::atof(s.c_str()) << '\n';
}