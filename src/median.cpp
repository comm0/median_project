
#include <iostream>

#include "median.hpp"

namespace median
{

template <typename DataType>
Median<DataType>::Median()
{

}

template <typename DataType>
DataType Median<DataType>::getMedian()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return internalGetMedian();
}

template <typename DataType>
DataType Median<DataType>::internalGetMedian()
{
    if (internalGetSize() == 0)
    {
        return 0;
    }
    else if (maxHeap_.size() > minHeap_.size())
    {
        return maxHeap_.top();
    }
    else if (maxHeap_.size() < minHeap_.size())
    {
        return minHeap_.top();
    }
    else
    {
        return (maxHeap_.top() + minHeap_.top()) / 2;
    }
}

template <typename DataType>
void Median<DataType>::insertData(DataType data)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (maxHeap_.size() > minHeap_.size())
    {
        if (data > maxHeap_.top())
        {
            minHeap_.push(data);
        }
        else
        { // swap
            minHeap_.push(maxHeap_.top());
            maxHeap_.pop();
            maxHeap_.push(data);
        }
    }
    else if (maxHeap_.size() < minHeap_.size())
    {
        if (data < minHeap_.top())
        {
            maxHeap_.push(data);
        }
        else
        { // swap
            maxHeap_.push(minHeap_.top());
            minHeap_.pop();
            minHeap_.push(data);
        }
    }
    else /* equal sizes */
    {
        if (data > internalGetMedian())
        {
            minHeap_.push(data);
        }
        else
        {
            maxHeap_.push(data);
        }
    }
}

template <typename DataType>
size_t Median<DataType>::getSize()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return internalGetSize();
}

template <typename DataType>
size_t Median<DataType>::internalGetSize()
{
	return maxHeap_.size() + minHeap_.size();
}

template class Median<int>;
template class Median<double>;
template class Median<float>;

} // namespace median
