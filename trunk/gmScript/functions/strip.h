#ifndef STRIP_H
#define STRIP_H
#include "../dataTypes.h"

class Strip
{
public:
	char findChar(const char* string, char find);
	char findChar(const char* string, char* charTable, int count);
	char findChar(const char* string,char* charTable);
	char findChar(const char* string, char findRange1,char findRange2);

	int findCharRetIndex(const char* text, char symbol);	//returns -1 als symb0ol er niet is 
	dataType* GMSfindVar(const char* command, int varCount);


	//char findChar(char* string, char find, int until);	//until = tot alphabet letter, of cijfer, teken etc
	//char findChar(char* string, char findRange1, findRange2, int until);
}extern strip;

#endif