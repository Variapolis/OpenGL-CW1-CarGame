#include "ConsoleDebug.h"

void Log(std::string message){
std::cout<< "Debug Log: " << message << std::endl;
}

void LogIntValue(std::string message, int value, std::string message2)
{
	std::cout << "DebugValue Log: "<< message << value << message2 << std::endl;
}

void LogIntValue(std::string message, int value)
{
	std::cout << "DebugValue Log: " << message << value << std::endl;
}