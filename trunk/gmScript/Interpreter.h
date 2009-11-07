#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "dataTypes.h"
#include "functions.h"
#include "../GUI/simpleGUI.h"

extern gui*		consoleWindow;
extern textbox*	consoleText;
extern button*	consoleButton;

class Interpreter
{
public:
	//vector<GMSvar)v....
	static void init();
	static int execute(const char* script);
	//onder: functies die checken of het een var is,functie of anders.. etc
	static bool handleVar(const char* script);
	static bool findVarName(char* name);
	//bool handeFunc
	//bool oop??
}extern interpreter;


void executeConsoleScript();

#endif