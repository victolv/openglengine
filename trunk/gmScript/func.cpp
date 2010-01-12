#include "func.h"


std::list<function*> GMSfunctions;

function::function(void* func,int* Parameters,int parameternum,int Return,char* Name)
{
	theFunc = func;
	parameterList = new int[parameternum];
	memcpy(parameterList, Parameters,sizeof(int)*parameternum);
	parameterNum = parameternum;
	theReturn = Return;
	name = Name;
	parameterSize = 0;

	for(int i = 0;i< parameterNum;i++){
		switch(Parameters[i])
		{
		case MINT: parameterSize += sizeof(int);
			break;
		case MCHAR: parameterSize += sizeof(int);
			break;
		case MCHARP: parameterSize += sizeof(char*);
			break;
		case MFLOAT: parameterSize += sizeof(int);
			break;
		case MDOUBLE: parameterSize += sizeof(double);
			break;

		default: parameterSize += sizeof(void*);
		}
	}
	GMSfunctions.push_back(this);
}

dataType* function::exec(dataType* args[]){
	char paramData[1000];//ook test
	int size = 0;

	if(parameterNum != 0)
	for(int i = 0;i < parameterNum;i++)
	{
		memcpy(&paramData[size], args[i]->var, args[i]->size);
		size += args[i]->size;
	}

	//va_end;
	int* dataLoc;
	void* temp = (int*)&paramData;
	dataLoc = (int*)&paramData;
	int location = (int)theFunc;
	char** test2 = (char**)paramData;
	//ecx counter

	int retSize = GMSsizeof(theReturn);
	int returnMe = 0;


	_asm{
		mov eax, 0;
		cmp eax,parameterSize;
		je caller;
		sub esp, parameterSize;
		mov edx, 0;
		mov ecx, dataLoc;//ecx = stack
pusher:
		mov al, byte ptr[ecx+edx];//ecx =
		mov byte ptr[esp+edx], al;
		inc edx;
		cmp edx, parameterSize;//enough bytes pushed?
		jne Pusher;
caller:
		call location;//function
		//add esp, parameterSize;//restore stack
		add esp, parameterSize;
		cmp retSize,0;
		je end;
		mov edx,0;

		popper://pop them values of stack
		mov returnMe, eax;

end:
	}
	if(retSize == 0)
		return 0;
	
	dataType* retData = new dataType(returnMe);
	retData->size = retSize;
	retData->type = theReturn;

	return retData;
}