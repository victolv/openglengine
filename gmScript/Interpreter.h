#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "dataTypes.h"
#include "func.h"
#include "functions/debug.h"
//#include "../GUI/simpleGUI.h"

//extern gui*		consoleWindow;
//extern textbox*	consoleText;
//extern button*	consoleButton;

class Interpreter
{
public:
	//vector<GMSvar)v....
	void init();
	int execute(const char* script);
	//onder: functies die checken of het een var is,functie of anders.. etc
	bool handleVar(const char* script);
	bool findVarName(char* name);
	//bool handeFunc
	//bool oop??
}extern interpreter;


void executeConsoleScript();

#endif