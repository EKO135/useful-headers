#ifndef HIDE_ACTIVE_WINDOW_INCLUDED
#define HIDE_ACTIVE_WINDOW_INCLUDED

#include <Windows.h>

void hideActiveWindow(int millisecondsUntilRestore)
{
	HWND currentActiveWindowHandle = GetForegroundWindow();

	ShowWindow(currentActiveWindowHandle, SW_HIDE);
	Sleep(millisecondsUntilRestore);
	ShowWindow(currentActiveWindowHandle, SW_SHOW);
}

#endif
