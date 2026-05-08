// Nate Newhart
// DeltaTime.hpp

#pragma once

#include <chrono>

class DeltaTimer
{
public:
	DeltaTimer();

	float  GetTimeFloat(); // Return seconds between last frame and current as float
	double GetTimeDouble();  // Return seconds between last frame and current as double

private:
	template<typename T>
	T GetDeltaTime();

private:
	std::chrono::high_resolution_clock::time_point prevTime; // The last time measurement
};

// -------------------------------- Inline Function Definitions --------------------------------

inline DeltaTimer::DeltaTimer() : prevTime(std::chrono::high_resolution_clock::now()) {}

template<typename T>
T DeltaTimer::GetDeltaTime()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<T> deltaTime = currentTime - prevTime;
	prevTime = currentTime;
	return deltaTime.count();
}

inline float DeltaTimer::GetTimeFloat()
{
	return GetDeltaTime<float>();
}

inline double DeltaTimer::GetTimeDouble()
{
	return GetDeltaTime<double>();
}