#ifndef FUNC_H
#define FUNC_H
#include <cstdarg>
#include <list>
#include "dataTypes.h"

class function : public data{
public:
	void* theFunc;
	int* parameterList;
	int parameterNum;
	int parameterSize;
	int theReturn;
public:
	function(void* func,int* Parameters,int parameternum,int Return,char* Name);
	dataType* exec(dataType* args[]); //neemt *dataType als parameter
};	
extern std::list<function*> GMSfunctions;

#endif