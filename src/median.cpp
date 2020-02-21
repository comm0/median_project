
#include <iostream>

#include "median.hpp"

template <typename DataType>
Median<DataType>::Median()
{

}

template <typename DataType>
DataType Median<DataType>::getMedian()
{
	if (getSize() == 0)
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
        if (data > getMedian())
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
	return maxHeap_.size() + minHeap_.size();
}

template <typename DataType>
void Median<DataType>::printData()
{
    auto med = getMedian();
    while(maxHeap_.size())
        { std::cout << maxHeap_.top() << "_"; maxHeap_.pop();}

    std::cout << "_(" << med << ")_";

    while(minHeap_.size())
        { std::cout << minHeap_.top() << "_"; minHeap_.pop();}
}

template class Median<int>;
template class Median<double>;
