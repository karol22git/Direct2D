#pragma once
#include <chrono>
class Timer
{
public:
	Timer() : begin(std::chrono::steady_clock::now()) {}
	void Tick() {
		
	}
	std::chrono::steady_clock::time_point GetBeginMoment() {
		return begin;
	}


private:
	std::chrono::steady_clock::time_point begin;
};

