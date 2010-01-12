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

	//datatype awnser...
	int nextVar = 0;
	nextVar = strip.findLegalVarCharRetIndex(&math[nextVar]);
	int awnser = *(int*)((strip.GMSfindVar(&math[nextVar]))->var);
	for(int i = 0;;i++){
		for(;strip.isLegalVarChar(math[nextVar]);nextVar++){}
		nextVar += strip.findLegalVarCharRetIndex(&math[nextVar]);

		switch(strip.findChar(math,"+-*/,(;",i)){
			case '+':
				awnser += *(int*)(strip.GMSfindVar(&math[nextVar]))->var;
				break;
			case '-':
				awnser -= *(int*)(strip.GMSfindVar(&math[nextVar]))->var;
				break;
			case '*':
				awnser *= *(int*)(strip.GMSfindVar(&math[nextVar]))->var;
				break;
			case '/':
				awnser /= *(int*)(strip.GMSfindVar(&math[nextVar]))->var;
				break;
			case ',':
			case '(':
			case ';':
			case 0:
				return new dataType(awnser);
		}
	}
	return 0;
}
