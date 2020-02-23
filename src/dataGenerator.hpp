
#pragma once

#include <ctime>
#include <random>

// compile-time random number generator based on article
// https://mklimenko.github.io/english/2018/06/04/constexpr-random/

namespace data
{

template <typename T, std::size_t size_>
class DataGenerator
{
public:
    constexpr auto operator () (const T max, const T min = 0) const
    {
        return uniform_distribution(min, max);
    }

private:

    constexpr static auto time_from_string(const char* str, int offset)
    {
        return static_cast<std::uint32_t>(str[offset] - '0') * 10 +
            static_cast<std::uint32_t>(str[offset + 1] - '0');
    }

    constexpr static auto get_seed_constexpr()
    {
        auto t = __TIME__;
        return time_from_string(t, 0) * 60 * 60 + time_from_string(t, 3) *
            60 + time_from_string(t, 6);
    }

    constexpr static std::uint32_t uniform_distribution(std::uint32_t& previous)
    {
        previous = ((lce_a_ * previous + lce_c_) % lce_m_);
        return previous;
    }

    constexpr static double uniform_distribution_n(std::uint32_t& previous)
    {
        auto dst = uniform_distribution(previous);
        return static_cast<double>(dst) / lce_m_;
    }

    constexpr static auto uniform_distribution(T min, T max)
    {
        std::array<T, size_> dst{};
        auto previous = get_seed_constexpr();
        for (auto& el : dst)
            el = static_cast<T>(uniform_distribution_n(previous) * (max - min) + min);
        return dst;
    }

    static constexpr int lce_a_ = 4096;
    static constexpr int lce_c_ = 150889;
    static constexpr int lce_m_ = 714025;
};

}  // namespace data