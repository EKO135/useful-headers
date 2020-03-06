#ifndef OPEN_WEBPAGE_INCLUDED
#define OPEN_WEBPAGE_INCLUDED

#include <Windows.h>

// state can be one of the WM_ enum values, such as WM_MAXIMISE or WM_MINIMIZE
// NOTE: the state parameter doesn't seem to do anything
void openWebpage(const char* url, int state)
{
	ShellExecute
	(
		NULL, // HWND
		NULL, // lpOperation
		url,  // url passed to function to be opened
		NULL, // lpParameters
		NULL, // lpDirectory
		state // nShowCmd enum value to use to open window (e.g. WM_MAXIMISE)
	);
}

#endif
