#pragma once
#include <iostream>
#include <Windows.h>


enum LOG_LEVEL
{
	LOGLEVEL_DEBUG, LOGLEVEL_WARNING, LOGLEVEL_ERROR
};

static void logMessage(const char* message, LOG_LEVEL level)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	switch (level)
	{
	case LOGLEVEL_DEBUG:
		SetConsoleTextAttribute(hConsole, 13);
		std::cout << "[ENGINE][DEBUG]: " << message << std::endl;
		break;
	case LOGLEVEL_WARNING:
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "[ENGINE][WARNING]: " << message << std::endl;
		break;
	case LOGLEVEL_ERROR:
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "[ENGINE][ERROR]: " << message << std::endl;
		break;
	default:
		break;
	}
}
