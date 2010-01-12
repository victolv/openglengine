#include "datatypes.h"
#include "functions/functions.h"

std::list<const char*> stringTable;
std::vector<void*> addresTable;
std::vector<int> typeTable;

std::list<dataType*> variables;
//std::list<dataTypeObjects> objects;

dataType::dataType(int value){
	type = MINT;
	var = new int;
	*(int*)var = value;
	size = sizeof(int);
	isConst = true;
}

dataType::dataType(int value, const char* name){
	type = MINT;
	var = new int;
	*(int*)var = value;
	this->name = name;
	variables.push_back(this);
	size = sizeof(int);
}

dataType::dataType(char* value){
type = MCHARP;
var = new char*;
*(char**)var = value;/*
*(char**)var = new char[strlen(value)+10];
strcpy((char*)var,value);
*/
size = sizeof(char*);
isConst = true;
variables.push_back(this);
}
dataType::dataType(char* value, const char* name){
type = MCHARP;
this->name = name;
var = new char*;
var = new char[strlen(value)+1];
strcpy((char*)var,value);
size = sizeof(char*);
variables.push_back(this);
}


dataType::dataType(void* value){
	//gebruik deze niet, weet type niet.
	size = sizeof(void*);
	isConst = true;

}
dataType::dataType(void* value, const char* name){
	var = value;
	this->name = name;
	variables.push_back(this);
	size = sizeof(int);
}

dataType* findVar(const char* name)
{
	int i = 0;
	char* c = (char*)name;

 	for(c;!isalpha(*c) && *c != '\0';c++)
	{}
	while(isalnum(*(c + i)))
		i++;

	for(std::list<dataType*>::iterator it = variables.begin();it != variables.end();it++)	{
		if(isStringPresent((*it)->name, c))
			return (*it);
	}
}

dataType& dataType::operator=(const int value)
{
	if(type == MINT)
	*(int*)var = value;
	else
	{
	type = MINT;
	var = new int;
	*(int*)var = value;
	return *this;
	}

}
dataType& dataType::operator=(const char* value)
{
	if(type == MCHAR)
		*(const char**)var = value;
	else
	{
	type = MCHARP;
	var = new char;
	*(const char**)var = value;
	return *this;
	}
}


dataType& dataType::operator=(const dataType value)
{
	if(value.size > size)
		var = new char[value.size];//var = value.size bytes  

	memcpy(var,value.var,value.size);
	type = value.type;
	size = value.size;
return *this;
}


char* getTypeName(dataType* var){
	switch(var->type){
	case MVOID: return "void";
	case MINT: return "int";
	case MCHAR: return "char";
	case MCHARP: return "char*";
	case MFLOAT: return "float";
	}
}


int GMSsizeof(int type){
		switch(type)
		{
		case MINT: return sizeof(int);
			break;
		case MCHAR: return sizeof(int);
			break;
		case MCHARP: return sizeof(char*);
			break;
		case MFLOAT: return sizeof(int);
			break;
		case MDOUBLE: return sizeof(double);
			break;

		default: return 0;
		}
}


dataType testInt(5,"a");














/*
dataType& dataType::operator=(const void* value)
{
	type = UNKNOWN;
	return *this;
}*/
/*
varInt::varInt(std::string name)
{
	stringTable.push_back(name.c_str());
	addresTable.push_back(new int);
}
*/