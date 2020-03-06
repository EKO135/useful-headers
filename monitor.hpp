#ifndef MONITOR_INCLUDED
#define MONITOR_INCLUDED

#include <Windows.h>

// status=true  : monitor will be turned ON
// status=false : monitor will be turned OFF
void enableMonitor(bool status)
{
	switch(status)
	{
	case true:
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)-1);
	case false:
		SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM)2);
	}
}

#endif
