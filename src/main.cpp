
#include <thread>
#include <vector>
#include <iostream>

#include "median.hpp"
#include "dataGenerator.hpp"

constexpr int SENDER_NUMBER = 10; //move it to some namespace
constexpr int SENDER_REPEAT = 10;

constexpr Functor<int, SENDER_NUMBER * SENDER_REPEAT> f;
auto dbls = f(100);

void sender(Median<double>& median, int threadIndex)
{
    //auto dbls = f(0, 10);
    //for (auto& dbl : dbls)
    auto offset = 10 * threadIndex;
    for (int i = 0 + offset; i < 10 + offset; ++i)
        std::cout << "dbl: " << dbls[i] << "\n";
    std::cout << "\n\n";

    for (int i = 0; i < SENDER_REPEAT; ++i)
        median.insertData(dbls[0]);
}

int main()
{
    Median<double> median;
    std::vector<std::thread> threads;
    for (int i = 0; i < SENDER_NUMBER; ++i)
        threads.emplace_back(sender, std::ref(median), i);

    for (auto& thread : threads)
        thread.join();

    median.printData();

    return 0;
}
