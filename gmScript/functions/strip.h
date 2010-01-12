#ifndef STRIP_H
#define STRIP_H
#include "../dataTypes.h"
#include "../func.h"
#include "functions.h"


class Strip
{
public:
	struct StripResults{
		int index1;
		int index2;
		int index3;
		int number;
		bool succes;
	}results;
	char findChar(const char* string, char find);
	char findChar(const char* string, char* charTable, int count);
	char findChar(const char* string,char* charTable);
	char findChar(const char* string, char findRange1,char findRange2);
	int findCharRetIndex(const char* text, const char* symbols);
	int findCharRetIndex(const char* text, char symbol);	//returns -1 als symb0ol er niet is 
	int findLegalVarCharRetIndex(const char* text);
	dataType* GMSfindVar(const char* command, int varCount);
	dataType* GMSfindVar(const char* command);

	int findAlNumRetIndex(const char* string);
	int findDigitRetIndex(const char* string);
	bool isLegalVarChar(int c);


	bool GMSisFunction(const char* string);
	function* findFunction(const char* string);
	function* findFunction(const char* string,dataType** params);//function overloading.
	dataType** findFuncArgs(function* func, const char* functionArgs);
	dataType** findFuncArgs(const char* functionArgs);
	//int* createArgList(dataType**);

	//char findChar(char* string, char find, int until);	//until = tot alphabet letter, of cijfer, teken etc
	//char findChar(char* string, char findRange1, findRange2, int until);
}extern strip;

#endif