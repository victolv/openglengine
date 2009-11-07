#include "functions.h"
#include "../dataTypes.h"
/*int GMScalculateString(const char* math)
{
	int awnser = *(int*)((strip.GMSfindVar(math,0))->var);
	for(int i = 0;;i++){
		switch(strip.findChar(math,"+-/*",i)){
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
				return awnser;
		}
	}
}*/

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