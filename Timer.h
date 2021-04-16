#ifndef _H_TIMER
#define _H_TIMER

#include <chrono>
#include "Instrumentor.h"

#define PROFILING 1
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION()
#endif

//	RAII Timer.
//		Results written to JSON file.
class InstrumentationTimer
{
public:
	InstrumentationTimer(const char*);
	void Stop();
	~InstrumentationTimer();
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimepoint;
	const char* m_task;
	bool m_isStopped;
};

#endif