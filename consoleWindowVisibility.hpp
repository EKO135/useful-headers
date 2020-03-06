#ifndef CONSOLE_WINDOW_VISIBILITY_INCLUDED
#define CONSOLE_WINDOW_VISIBILITY_INCLUDED

#include <Windows.h>

// status=true  : console window will be SHOWN
// status=false : console window will be HIDDEN
void showConsoleWindow(bool status)
{
	switch(status)
	{
	case true:
		ShowWindow(GetConsoleWindow(), SW_SHOW);
	case false:
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
}

#endif
