
#pragma once

#include <queue>
#include <cstddef>

template <typename DataType>
class Median
{
public:
    Median();

    DataType getMedian();

    void insertData(DataType data);

    size_t getSize();

    void printData();

private:
    std::priority_queue<DataType> maxHeap_;
    std::priority_queue<DataType, std::vector<DataType>, std::greater<DataType> > minHeap_;
};
