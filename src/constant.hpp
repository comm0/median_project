#pragma once

#include "dataGenerator.hpp"

namespace constant
{
// with new data-type, new template declaration is needed in median.cpp
using DataType = double;

constexpr int SENDER_NUMBER = 10;
constexpr int SENDER_REPEAT = 10;
constexpr int TOTAL_DATA_NUM = SENDER_NUMBER * SENDER_REPEAT;
constexpr int MAX_DATA_VALUE = 100;

data::DataGenerator<DataType, TOTAL_DATA_NUM> dataGenerator;

auto DATA_ARRAY = dataGenerator(MAX_DATA_VALUE);

}  // namespace constant

