#include "func.h"



function::function(void* func,int* Parameters,int parameternum,int Return,char* Name)
{
	theFunc = func;
	parameterList = Parameters;
	parameterNum = parameternum;
	theReturn = Return;
	name = Name;
	parameterSize = 0;

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

dataType* function::exec(dataType* args[]){
	char paramData[1000];//ook test
	int size = 0;

	for(int i = 0;i < parameterNum;i++)
	{
		memcpy(&paramData[size], args[i]->var, args[i]->size);
		size += args[i]->size;
	}
	//va_end;
	int dataLoc = (int)&paramData;
	int location = (int)theFunc;
	//ecx counter
	_asm{
		mov eax, 0;
		cmp eax,parameterSize;
		je caller;
		sub esp, parameterSize;
		mov edx, 0;
		mov ecx, dataLoc;//ecx = function
pusher:
		mov al, byte ptr[ecx+edx];//ecx =
		mov byte ptr[esp+edx], al;
		inc edx;
		cmp edx, parameterSize;//enough bytes pushed?
		jne Pusher;
caller:
		call location;//function
		add esp, parameterSize;//restore stack
	}

	//return////////
	//switch(theReturn){
	//	case INT:
			//return new dataType(
	//}
	return 0;
}