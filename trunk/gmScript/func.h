#ifndef FUNC_H
#define FUNC_H
#include <cstdarg>
#include "dataTypes.h"

class function
{
public:
	void* theFunc;
	char* name;
	int* parameterList;
	int parameterNum;
	int parameterSize;
	int theReturn;
public:
	function(void* func,int* Parameters,int parameternum,int Return,char* Name);
	dataType* exec(dataType* args[]); //neemt *dataType als parameter
};	

#endif