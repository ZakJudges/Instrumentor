#ifndef _H_INSTRUMENTOR
#define _H_INSTRUMENTOR

#include <iostream>
#include <string>
#include <fstream>

struct ProfileResult
{
	std::string Name;
	long long Start, End;
	uint32_t ThreadID;
	ProfileResult(const std::string& name, long long start, long long end, uint32_t thread) : Name(name), Start(start), End(end), ThreadID(thread) {}
};

struct InstrumentationSession
{
	std::string Name;
	InstrumentationSession(const std::string& name) : Name(name) {}
};

//	Writes out the result of timings to a JSON file.
//	Displayed using chrome://tracing
class Instrumentor
{
public:
	Instrumentor();
	void BeginSession(const std::string& name, const std::string& filepath = "results.json");
	void EndSession();
	void WriteProfile(const ProfileResult& result);
	void WriteHeader();
	void WriteFooter();
	static Instrumentor& Get();

private:
	InstrumentationSession* m_currentSession;
	std::ofstream m_outputStream;
	int m_profileCount;
};

#endif