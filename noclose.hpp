#define NOCLOSE_HPP
#ifndef NOCLOSE_HPP

#include <Windows.h>

void grey_x_min()
{
    HWND hwnd = GetConsoleWindow();
    HMENU hmenu = GetSystemMenu(hwnd, FALSE);
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED);
    EnableMenuItem(hmenu, SC_MINIMIZE, MF_GRAYED);
}

#endif // NOCLOSE_HPP
