#ifndef GREY_X_HPP
#define GREY_X_HPP

#include <Windows.h>

void grey_x_min()
{
    HWND hwnd = GetConsoleWindow(); // get handle on window
    HMENU hmenu = GetSystemMenu(hwnd, FALSE); // get handle on that windows action menu
    EnableMenuItem(hmenu, SC_CLOSE, MF_GRAYED); // grey its X button
    EnableMenuItem(hmenu, SC_MINIMIZE, MF_GRAYED); // grey its - button
}

#endif // GREY_X_HPP
