#pragma once
#include <ctime>
class Timer
{
public:
	Timer()
	{
		startTime = std::clock();
	}
	double runtime()
	{
	//	std::cout <<"time::" << startTime << " " << std::clock() << std::endl;

		return (long double)(std::clock() - startTime)/CLOCKS_PER_SEC;
	}
private:
	std::clock_t startTime;
};
