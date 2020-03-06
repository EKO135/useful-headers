#ifndef SLEEP_FOR_MS_INCLUDED
#define SLEEP_FOR_MS_INCLUDED

#include <thread>
#include <chrono>

// mingw apparently doesn't support threading yet, so this header file is not currently in use

inline void sleepForMilliseconds(int milliseconds)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

#endif
