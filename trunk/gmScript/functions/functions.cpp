#include "functions.h"
#include "../dataTypes.h"

bool isStringPresent(const char* string1, const char* string2){
	for(int i = 0;string1 != '\0' && string2 != '\0' && isalnum(string2[i]);i++){
		if(string1[i] != string2[i])
			return false;
	}
	return true;
}

dataType* GMScalculateString(const char* math)
{
	int awnser = *(int*)((strip.GMSfindVar(math,0))->var);
	for(int i = 0;;i++){
		switch(strip.findChar(math,"+-*/",i)){
			case '+':
				awnser += *(int*)(strip.GMSfindVar(math,i+1))->var;
				break;
			case '-':
				awnser -= *(int*)(strip.GMSfindVar(math,i+1))->var;
				break;
			case '*':
				awnser *= *(int*)(strip.GMSfindVar(math,i+1))->var;
				break;
			case '/':
				awnser /= *(int*)(strip.GMSfindVar(math,i+1))->var;
				break;
			case 0:
				return new dataType(awnser);
		}
	}
	return 0;
}
