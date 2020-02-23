
#pragma once

#include <chrono>
#include <iostream>

// RAII timer

class Timer
{
public:
	Timer(const bool shallPrintRes = true) : shallPrintRes_(shallPrintRes)
	{
		start_ = std::chrono::high_resolution_clock::now();
	}
	~Timer()
	{
		Stop();
	}

private:
	void Stop()
	{
		auto endNow = std::chrono::high_resolution_clock::now();
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(start_).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endNow).time_since_epoch().count();
		auto duration = end - start;
		double ms = duration * 0.001;
		if (shallPrintRes_)
			std::cout << ms << "us\n";
	}

	std::chrono::time_point< std::chrono::high_resolution_clock> start_;
	bool shallPrintRes_;
};