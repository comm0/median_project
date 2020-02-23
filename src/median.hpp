
#pragma once

#include <cstddef>
#include <mutex>
#include <queue>

/* class for runtime median computing */

namespace median
{

template <typename DataType>
using MaxHeap = std::priority_queue<DataType>;

template <typename DataType>
using MinHeap = std::priority_queue<DataType, std::vector<DataType>, std::greater<DataType> >;

template <typename DataType>
class Median
{
public:
    Median();

    void insertData(DataType data);

    /* thread-safe median getter */
    DataType getMedian();

    /* thread-safe size getter */
    size_t getSize();

private:
    /* internal methods that assume they work */
    /* already mutexed part */
    DataType internalGetMedian();
    size_t internalGetSize();

    MaxHeap<DataType> maxHeap_;
    MinHeap<DataType> minHeap_;
    std::mutex mutex_;
};
} // namespace median