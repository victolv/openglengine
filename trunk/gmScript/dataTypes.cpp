#include "datatypes.h"

std::list<const char*> stringTable;
std::vector<void*> addresTable;
std::vector<int> typeTable;

std::list<dataType> variables;
//std::list<dataTypeObjects> objects;

dataType::dataType(int value){
	type = INT;
	var = new int;
	*(int*)var = value;
	size = sizeof(int);
}

dataType::dataType(int value, const char* name){
	type = INT;
	var = new int;
	*(int*)var = value;
	this->name = name;
	variables.push_back(*this);
	size = sizeof(int);
}

dataType::dataType(void* value){
	//gebruik deze niet, weet type niet.
	size = sizeof(void*);

}
dataType::dataType(void* value, const char* name){
	var = value;
	this->name = name;
	variables.push_back(*this);
	size = sizeof(int);
}

dataType& findVar(const char* name)
{
	int i = 0;
	char* c = (char*)name;

 	for(c;!isalpha(*c);c++)
	{}
	while(isalnum(*(c + i)))
		i++;

	for(std::list<dataType>::iterator it = variables.begin();it != variables.end();it++)	{
		if(!strncmp(it->name, c,i))
			return (*it);
	}
}

dataType& dataType::operator=(const int value)
{
	if(type == INT)
	*(int*)var = value;
	else
	{
	type = INT;
	var = new int;
	*(int*)var = value;
	return *this;
	}

}
dataType& dataType::operator=(const char* value)
{
	if(type == CHAR)
		*(const char**)var = value;
	else
	{
	type = CHAR;
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