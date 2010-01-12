#include <iostream>

#include "debug.h"
Debug debug;


Debug::Debug()
{
	error = printError;
}

void printError(const char *text){
	std::cout << text << std::endl;
}