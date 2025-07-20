#include <iostream>
#include <limits>
#include "division.h"

double divide(double numerator, double denominator)
{
    if (denominator == 0)
    {
        std::cout << "Division with zero is undefined" << '\n';
        return std::numeric_limits<double>::quiet_NaN();
    }

    return numerator / denominator;
}