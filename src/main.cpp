
#include <iostream>

#include "median.hpp"

int main()
{
    Median<double> median;

    double i = 0;
    for (int n = 0; n < 10; ++n)
        median.insertData(i++);

    median.printData();

    return 0;
}
