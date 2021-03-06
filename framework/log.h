#pragma once
#include <iostream>
#include <Windows.h>

namespace framework
{
	enum LOG_LEVEL
	{
		LOGLEVEL_DEBUG, LOGLEVEL_WARNING, LOGLEVEL_ERROR
	};

	static void logMessage(const char* message, LOG_LEVEL level)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		switch (level)
		{
		case framework::LOGLEVEL_DEBUG:
			SetConsoleTextAttribute(hConsole, 13);
			std::cout << "[FRAMEWORK][DEBUG]: " << message << std::endl;
			break;
		case framework::LOGLEVEL_WARNING:
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "[FRAMEWORK][WARNING]: " << message << std::endl;
			break;
		case framework::LOGLEVEL_ERROR:
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "[FRAMEWORK][ERROR]: " << message << std::endl;
			break;
		default:
			break;
		}
	}
}