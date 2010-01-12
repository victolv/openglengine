#ifndef DEBUG_H
#define DEBUG_H
#include <sstream>

class Debug{
public:
	Debug();
	void (*error)(const char*);
}extern debug;

void printError(const char* text);

#endif