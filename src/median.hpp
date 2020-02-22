
#pragma once

#include <cstddef>
#include <mutex>
#include <queue>

template <typename DataType>
using MaxHeap = std::priority_queue<DataType>;

template <typename DataType>
using MinHeap = std::priority_queue<DataType, std::vector<DataType>, std::greater<DataType> >;

template <typename DataType>
class Median
{
public:
    Median();

    /* thread-safe median getter */
    DataType getMedian();

    void insertData(DataType data);

    void printData(); // todo: remove

private:
    DataType internalGetMedian();
    size_t getSize();

    MaxHeap<DataType> maxHeap_;
    MinHeap<DataType> minHeap_;
    std::mutex mutex_;
};
