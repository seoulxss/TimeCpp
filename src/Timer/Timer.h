#pragma once
#include <chrono>
#include <iostream>

//Just use this, if u want to measure the time automatically
class TimerInScope
{
public:
	TimerInScope() noexcept
	{
		m_Start = Start();
	}

	~TimerInScope() noexcept
	{
		const auto end = Stop();
		m_Duration = end - m_Start;

		float ms = m_Duration.count() * 1000.0f;
		float s = ms / 1000.0f;

		std::wcout << "This took: " << ms << "ms!\n";
		std::wcout << "This took: " << s << "Seconds!\n";
	}


private:
	inline auto Start() const noexcept
	{
		return std::chrono::high_resolution_clock::now();
	}

	inline auto Stop() const noexcept
	{
		return std::chrono::high_resolution_clock::now();
	}

	std::chrono::duration<float> m_Duration = {};
	std::chrono::time_point<std::chrono::steady_clock> m_Start = {};
};

//Use this to manual start and stop
class Timer
{
public:
	Timer() = default;

	inline float GetDurSec() noexcept
	{
		m_Duration = m_End - m_Start;
		const float Sec = m_Duration.count() * 1000.0f;
		return Sec;
	}

	inline float GetDurMs() noexcept
	{
		m_Duration = m_End - m_Start;
		const float Ms = m_Duration.count();
		return Ms;
	}

	inline auto Start() noexcept
	{
		return m_Start = std::chrono::high_resolution_clock::now();
	}

	inline auto Stop() noexcept
	{
		return m_End = std::chrono::high_resolution_clock::now();
	}

private:
	std::chrono::duration<float> m_Duration = {};
	std::chrono::time_point<std::chrono::steady_clock> m_Start = {};
	std::chrono::time_point<std::chrono::steady_clock> m_End = {};


};