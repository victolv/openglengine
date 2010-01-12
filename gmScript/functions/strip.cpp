#include "strip.h"
#include "debug.h"
#include <iostream>

Strip strip;

char Strip::findChar(const char* string, char find)
{
for(string;*string != find;string++)
{
	if(*string == 0 || *string == ';')
		return false;
}
return find;
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
return -1;
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

int Strip::findAlNumRetIndex(const char* string){
	int i = 0;
	for(;!isalnum(string[i]) && string[i] != '\0';i++){}
	return i;
}
int Strip::findDigitRetIndex(const char* string){
	int i = 0;
	for(;!isdigit(string[i]) && string[i] != '\0';i++){}
	return i;
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
dataType* Strip::GMSfindVar(const char* command){
	command += findLegalVarCharRetIndex(command);
//wijst naar een var.

	if(GMSisFunction(command))
	{
		function* func = 0;
		dataType** args = findFuncArgs(&command[results.index2]);
			func = findFunction(command,args);
			return func->exec(args);
	}
			else if(*command == '\"'){
			int len = findCharRetIndex(&command[1],'\"') + 1;
			char* strVar = new char[len+1];
			strncpy(strVar,&command[1],len);
			strVar[len] = 0;
			dataType* str = new dataType(strVar);
			str->isConst = true;
			return str;
		}

	else if(isdigit(*command)){
	int i = 0;
	for(i;isalnum(command[i]);i++){}
	char* var = new char[i+1];
	var[i] = 0;
	strncpy(var,command,i);

	dataType* result = new dataType(atoi(var)); 
	result->isConst = true;
	return result;
	}
	else if(isalpha(*command)){
	return findVar(command);
	}
}

	
dataType* Strip::GMSfindVar(const char* command, int varCount){
	int number = 0;
	bool atVar = true;
	const char* c = command;

	//point naar eerste var/number/func..
	for(int i = 0;!isLegalVarChar(c[i]);i++){}


	for(int i = 0;*c != '\0';i++,c++){
		if(isalnum(*c)){/////////////////////////////////
			if(atVar != true  && number != varCount && findCharRetIndex("/*+-.&\"\'",*c) == -1){
				atVar = true;
				number++;
			}
		}
		else atVar = false;

		if(number == varCount)
			break;
	}////////////////////////////////////////
	int calc = 0;
	calc = 5;
	calc = 0;


	c += findLegalVarCharRetIndex(c);


	
	int index = 0;
	int start = 0;
	for(;isLegalVarChar(c[index]);index++){}
	start = index;
	if(*c == '\"'){
		index = findCharRetIndex(c+1,'\"')+1;
	}


		char* ctemp = new char[index+1];
		strncpy(ctemp,c,index);
		ctemp[index] = 0;
	
		if(*c == '\"'){
			int len = findCharRetIndex(c,'\"');
			char* strVar = new char[index+1];
			strncpy(strVar,ctemp,index);
			strVar[index-1] = 0;
			dataType* str = new dataType(strVar);
			str->isConst = true;
			return str;
		}







//			char temp = findLegalVarCharRetIndex(c);


		if(findChar(ctemp,"+-*/^") != 0)
		{
		calc = *(int*)GMScalculateString(c)->var;
		if(calc != 0)
			return new dataType(calc);
		}


		if(GMSisFunction(ctemp)){
			function* func = 0;
			dataType** args = findFuncArgs(ctemp);
			func = findFunction(ctemp,args);
			if(func == 0){
				std::stringstream message;
				debug.error("a");
			}
			else
			return func->exec(args);
		}

		int type = findCharRetIndex(ctemp,'.');
		if(type != -1 && type < index)// zit punt midden in een cijfer?
		return new dataType(atof(ctemp));

		if(isdigit(*ctemp))
		return new dataType(atoi(ctemp));
		else if(isalpha(*ctemp))
		return findVar(ctemp);

		return 0;
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

int Strip::findCharRetIndex(const char* text, const char* symbols){
{
	const char* i;
	int number = 0;
	//hoeveel chars heeft charTable?
	for(i = symbols;*i != '\0';i++, number++)
	{int a;
	}

	while(*text != '\0'){
	
		for(int i = 0;i <= number;i++){
		if(*text == symbols[i])
		{
			return i;  
		}
	}

		text++;}
return -1;
}
}


bool Strip::GMSisFunction(const char* string){
	int index = 0;
	for(index;*string == isalnum(*string);string++,index++){
	}
	results.index1 = index;
		//ok, string wijst nu naar een letter/cijfer.

	for(const char* pointer = string;isalnum(*pointer) || isspace(*pointer) || *pointer == '(';pointer++,index++){
		if(*pointer == '('){
		results.index2 = index;//index2 wijst nu naar '(' (begin van argumenten van de functie
		return true;
		}
	}
	results.index2 = 0;
	return false;
}

function* Strip::findFunction(const char* string){
		for(std::list<function*>::iterator it = GMSfunctions.begin();it != GMSfunctions.end();it++)	{
		if(isStringPresent((*it)->name,string))
			return (*it);

		}
	return 0;
}

function* Strip::findFunction(const char* string,dataType** params){
	function* func = 0;
		for(std::list<function*>::iterator it = GMSfunctions.begin();it != GMSfunctions.end();it++)	{
			if(isStringPresent((*it)->name,string) && (*it)->parameterNum == results.number){
				for(int i = 0;i < (*it)->parameterNum || i == 0;i++){
					 if(params == 0 && (*it)->parameterNum == 0)
						return (*it);
					else if(params == 0)
						continue;
					else if((*it)->parameterList[i] == params[i]->type){
						func = (*it);
						if(func->parameterNum == i+1)
							return (*it);
					}
				}
			}
		}
	return 0;
}



/*dataType** Strip::findFuncArgs(const char* functionArgs){
	int paramNum = 0;
	bool atLastParam = false;
	dataType* argArray[20];
	int functionDepth = 0; //0 == we zijn niet in een andere functie
	for(functionArgs;*functionArgs == '(' || *functionArgs == ' ';functionArgs++){}
	//wijzen we naar het eerste argument?
	

	for(int i = 0;;i++){

	//	if(functionArgs[i] == '(')
		//	functionDepth++;
		if(functionArgs[i] == ')'){
			if(functionDepth == 0)
				break;
			functionDepth--;//zitten wij binnen een andere functie?
		}

		if(GMSisFunction(functionArgs)){
			function* funcArg = findFunction(functionArgs);
			if(funcArg != 0){
				functionDepth++;// het zoeken van de argumenten
				argArray[paramNum] = funcArg->exec(findFuncArgs(&functionArgs[i]));
				paramNum++;
			}
		}
		//else if isObjectMember(functionArgs){}
		else{
			argArray[paramNum] = GMSfindVar(&functionArgs[i],0);
			paramNum++;
		}

		if(atLastParam == true)
			break;

		//zoek voor komma ',' en zet pointer op de argument daarna
		int temp = findCharRetIndex(&functionArgs[i],',');
		if(temp != -1)
			i += temp;
		else atLastParam = true;
		

		for(;!isalnum(functionArgs[i]);i++){
			if(functionArgs[i] == ')' && functionDepth == 0)
				break;
		}//laat pointer naar volgende arg wijzen.
		//quickfix,.... :(
		i--;
	}
	return argArray;
}*/



dataType* argArray[20];

dataType** Strip::findFuncArgs(function* func,const char* functionArgs){

	for(int i = 0;i < func->parameterNum ;i++){
	argArray[i] = GMSfindVar(functionArgs,i);
	}
	results.number = func->parameterNum;
	return argArray;
}

dataType** Strip::findFuncArgs(const char* functionArgs){
	//for(int i = 0;functionArgs[i] != 0;i++){
	//	if(functionArgs[i] = '('
	//}
	//findCharRetIndex(functionArgs,
	
	const char* index = 0;


	int functionDepth = 0;
	int argAmmount = 0;
	int beenhere = false;

	for(int i = 0;;i++){
		if(functionArgs[i] == '('){
			functionDepth++;
		
		}
		if(functionArgs[i] == ')'){
			if(functionDepth == 0)
				break;
			functionDepth--;
		}
		if(functionArgs[i] == ','){
			if(beenhere == false){
			results.number = 0;
			return 0;
			}
			argAmmount++;
			beenhere =false;
		}
		if(isalnum(functionArgs[i]) && argAmmount == 0&& beenhere == false){
			argAmmount++;
			beenhere = true;
		}
	}
	
	//buiten, we weten hoeveel args er zijn...
	results.number = argAmmount;

	if(argAmmount == 0)
		return 0;

	for(int i = 0;i < argAmmount ;i++){
	argArray[i] = GMSfindVar(functionArgs,i);
	}
	return argArray;
}

/*int findAlNumRetIndex(const char* string){
	for(int i = 0;string[i] != '\0' && string[i] != ';')
		if(isalnum(string[i]))
			return i;
	return -1;
}*/
//int findAlphaRetIndex(const char* string){
//}

bool Strip::isLegalVarChar(int c){
if(isalnum(c) || findChar("\"\'*&",c))
return true;
else
return false;
}
int Strip::findLegalVarCharRetIndex(const char* text){
	int i = 0;
	for(i;!isLegalVarChar(text[i]) && text[i];i++){}
	if(text[i] == '\0' || text[i] == ';')
		return 0;

	return i;
}