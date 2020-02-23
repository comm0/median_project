
#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

#include "constant.hpp"
#include "median.hpp"


void sender(median::Median<constant::DataType>& medianContainer, const std::uint32_t threadIndex)
{
    // distribute values between all working senders
    const auto offset = constant::SENDER_REPEAT * threadIndex;
    for (std::uint32_t i = offset; i < constant::SENDER_REPEAT + offset; ++i)
        medianContainer.insertData(constant::DATA_ARRAY[i]);
}

int main()
{
    median::Median<constant::DataType> medianContainer;
    std::vector<std::thread> threads;
    for (std::uint32_t i = 0; i < constant::SENDER_NUMBER; ++i)
        threads.emplace_back(sender, std::ref(medianContainer), i);

    for (auto& thread : threads)
        thread.join();


    std::cout << "\n RESULTs: \n";
    std::sort(constant::DATA_ARRAY.begin(), constant::DATA_ARRAY.end());
    const auto realMedian = constant::TOTAL_DATA_NUM % 2 != 0 ?
        constant::DATA_ARRAY[constant::TOTAL_DATA_NUM / 2] :
        (constant::DATA_ARRAY[constant::TOTAL_DATA_NUM / 2] + constant::DATA_ARRAY[(constant::TOTAL_DATA_NUM / 2) - 1]) / 2;

    std::cout << "realMedian: " << realMedian << "\n";
    std::cout << "getMedian :" << medianContainer.getMedian() << "\n";

    return 0;
}
