#include "functions.h"



function::function(void* func,int* Parameters,int parameternum,int Return,char* Name)
{
	theFunc = func;
	parameterList = Parameters;
	parameterNum = parameternum;
	theReturn = Return;
	name = Name;

	for(int i = 0;i< parameterNum;i++){
		switch(Parameters[i])
		{
		case INT: parameterSize += sizeof(int);
			break;
		case CHAR: parameterSize += sizeof(int);
			break;
		case FLOAT: parameterSize += sizeof(int);
			break;

		default: parameterSize += sizeof(void*);
		}
	}
}

dataType* function::exec(...){
	dataType* varObj[100];//test , placeholder
	char paramData[1000];//ook test

	va_list listPointer;
	va_start(listPointer, parameterNum);
	for(int i = 0;i < parameterNum;i++)
	{
		varObj[i] = va_arg(listPointer, dataType*);
		memcpy(paramData, varObj[i]->var, varObj[i]->size);
	}
	//va_end;

	int location = (int)theFunc;
	//ecx counter
	_asm{
		mov eax, parameterSize;
		cmp eax,0;
		je caller;
		sub esp, parameterSize;
		mov ecx, location;
pusher:
		mov al, byte ptr[ecx+edx];
		mov byte ptr[esp+edx], al;
		inc edx;
		cmp edx, parameterSize;
		jne Pusher;
caller:
		call location;
	}

	//return////////
	//switch(theReturn){
	//	case INT:
			//return new dataType(
	//}
	return 0;
}