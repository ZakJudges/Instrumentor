#include "Timer.h"

void SomeFunction()
{
	PROFILE_FUNCTION();
	//	Do stuff.
}

void SomeOtherFunction()
{
	PROFILE_FUNCTION();
	//	Do more stuff.
}

int main()
{
	Instrumentor::Get().BeginSession("Test Profile");
	SomeFunction();
	Instrumentor::Get().EndSession();

	return 0;
}