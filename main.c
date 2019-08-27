// had to do this in c because cpp date are messed
#include <time.h>
#include <stdio.h>

// date for the payload to activate
#define ACTIVATION_DAY 29
#define ACTIVATION_MONTH 8
#define ACTIVATION_YEAR 2020

// returns true if system time is passed the predefined activation date, false if it's not
bool isPassedActivationDate()
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	int currentDate = ((tm.tm_year + 1900) * 10000) + ((tm.tm_mon + 1) * 100 ) + tm.tm_mday; 
	int activationDate = (ACTIVATION_YEAR * 10000) + (ACTIVATION_MONTH * 100) + ACTIVATION_DAY;
	
	if (currentDate >= activationDate) // if the current date is equal to or greater than the activation date
	{
		return true;
	}
	else
	{
		return false;
	}
}
