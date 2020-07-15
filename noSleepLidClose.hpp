#pragma once
#define NOSLEEPLIDCLOSE_HPP
#ifndef NOSLEEPLIDCLOSE_HPP

#include <Windows.h>
#include <vector>

auto stop_close() -> void
{
    std::vector<std::string> pwrcmd;
    pwrcmd.emplace_back("powercfg /setdcvalueindex scheme_current sub_buttons lidaction 0");
    pwrcmd.emplace_back("powercfg /setacvalueindex scheme_current sub_buttons lidaction 0");
    // turn off lidclose sleep ^^^
    pwrcmd.emplace_back("powercfg /setdcvalueindex scheme_current 4f971e89-eebd-4455-a8de-9e59040e7347 7648efa3-dd9c-4e3e-b566-50f929386280 0");
    pwrcmd.emplace_back("powercfg /setacvalueindex scheme_current 4f971e89-eebd-4455-a8de-9e59040e7347 7648efa3-dd9c-4e3e-b566-50f929386280 0");
    // disable power button ^^^
    pwrcmd.emplace_back("powercfg /setactive scheme_current");
    // save these settings ^^^

    // info to execute commands in the same session
    STARTUPINFO info={sizeof(info)};
    PROCESS_INFORMATION processInfo;

    // iterate through the powercfg commands
    for (auto command : pwrcmd) {
        // using create process because it will not create a new session if the same system info is passed
        // meaning the commands can work off each other
        CreateProcess(NULL, LPSTR(command.c_str()), NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);
        WaitForSingleObject(processInfo.hProcess, INFINITE);
        CloseHandle(processInfo.hProcess);
        CloseHandle(processInfo.hThread);
        //std::cout << command.c_str() << std::endl;
    }
}

#endif // NOSLEEPLIDCLOSE_HPP
