
#include <gtest/gtest.h>

#include <algorithm>

#include "../src/dataGenerator.hpp"
#include "../src/median.hpp"
#include "timer.hpp"

namespace
{
const int MAX_ELE = 1000;
const bool SHALL_PRINT_MEASURMENT_RES = false;
}  // namespace

template<typename DataType>
struct MedianFixture : ::testing::Test
{
    using MyType = DataType;
    DataType MAX_DATA_VALUE = 1000;

    void SetUp() override
    {
        data::DataGenerator<DataType, MAX_ELE> dataGenerator;
        dataArray = dataGenerator(MAX_DATA_VALUE);
    }

    DataType getMedianFromArray(int i)
    {
        auto copyArray = dataArray; // todo: should copy only wanted part
        int size = i + 1;
        std::sort(copyArray.begin(), copyArray.begin() + size);
        return size % 2 != 0 ? copyArray[size / 2] :
            (copyArray[size / 2] + copyArray[(size / 2) - 1 ]) / 2;
    }

    median::Median<DataType> medianContainer;
    std::array<DataType, MAX_ELE> dataArray;
};

using DataTypes = testing::Types<int, double, float>;
TYPED_TEST_CASE(MedianFixture, DataTypes);

TYPED_TEST(MedianFixture, ShouldStartWithEmptyContainerAndIncreaseTotalSizeWithEveryAddition)
{
    EXPECT_EQ(this->medianContainer.getSize(), 0);

    for (int i = 0; i < MAX_ELE; ++i)
    {
        this->medianContainer.insertData(this->dataArray[i]);
        EXPECT_EQ(this->medianContainer.getSize(), i + 1);
    }
}

TYPED_TEST(MedianFixture, ShouldComputeProperMedianAfterEverySingleAddition)
{
    for (int i = 0; i < MAX_ELE; ++i)
    {
        this->medianContainer.insertData(this->dataArray[i]);

        TypeParam medianRes, rawArrayRes;

        {
            if (SHALL_PRINT_MEASURMENT_RES)
                std::cout << "medianHeap median get time: ";
            Timer t(SHALL_PRINT_MEASURMENT_RES);
            medianRes = this->medianContainer.getMedian();
        }
        
        {
            if (SHALL_PRINT_MEASURMENT_RES)
                std::cout << "rawArrayRes median get time: ";
            Timer t(SHALL_PRINT_MEASURMENT_RES);
            rawArrayRes = this->getMedianFromArray(i);
        }

        EXPECT_EQ(medianRes, rawArrayRes);
    }
}
