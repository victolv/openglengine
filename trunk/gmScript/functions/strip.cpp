#include "strip.h"

#include <iostream>

Strip strip;

char Strip::findChar(const char* string, char find)
{
for(string;*string != find;string++)
{}
return 1;
}//....................

char Strip::findChar(const char* string,char* charTable)
{
	char* i;
	int number = 0;
	//hoeveel chars heeft charTable?
	for(i = charTable;*i != '\0';i++, number++)
	{int a;
	}

	while(*string != '\0'){
	
		for(int i = 0;i <= number;i++){
		if(*string == charTable[i])
		{
			return charTable[i];  
		}
		std::cout << string << "\t" << charTable[i] << std::endl;
	}

string++;}
return 1;
}

char Strip::findChar(const char* string, char* charTable, int count){
	for(;*string != 0;string++){
		for(int i = 0;*(charTable+i) != '\0';i++){
			if(*string==*(charTable+i))
			{
				count--;
				if(count < 0)
				return *(charTable+i);
				else break;
			}
		}
	}
	return 0;
}

char Strip::findChar(const char* string, char findRange1,char findRange2)
{
	int number = findRange2 - findRange1;
while(*string != '\0'){

	for(int i = 0;i < number;i++){
		if(*string == findRange1 + i)
			return findRange1 + i;  
	}

string++;}
return 0;
}
//////////////////////////speciaal voor GMS/////////////////////////////// 
dataType* Strip::GMSfindVar(const char* command, int varCount){
	int number = 0;
	bool atVar = false;
	const char* c = command;
	for(int i = 0;*c != '\0';i++,c++){
		if(isalnum(*c)){/////////////////////////////////
			if(atVar != true  && number != varCount){
				atVar = true;
				number++;
			}
			else if(number == varCount)
				break;
		}
		else atVar = false;
	}////////////////////////////////////////
	int i;
		for(i = 0;isalnum(*(c+i));i++){}
		char* ctemp = new char[i+1];
		strncpy(ctemp,c,i);
		*(ctemp+i) = 0;

		if(isdigit(*ctemp))
		return new dataType(atoi(ctemp));
		else if(isalpha(*ctemp))
		return &findVar(ctemp);
}


int Strip::findCharRetIndex(const char* text, char symbol)
{
	int i = 0;
	while(*text != symbol){
		i++;
		if(*text == '\0' || *text == ';')
			return -1;
		text++;
	}
return i;
}


bool Strip::GMSisFunction(const char* string){
	int index = 0;
	for(index;*string == isalnum(*string);string++,index++){
	}
	results.index1 = index;
		//ok, string wijst nu naar een letter/cijfer.

	for(const char* pointer = string;isalnum(*pointer) || isspace(*pointer) || *pointer == '(';pointer++){
		if(*pointer == '('){
		results.index2 = index; 
		return true;
		}
	}
	return false;
}

function* Strip::findFunction(const char* string){
		for(std::list<function*>::iterator it = GMSfunctions.begin();it != GMSfunctions.end();it++)	{
		if(isStringPresent((*it)->name,string))
			return (*it);

		}
	return 0;
}