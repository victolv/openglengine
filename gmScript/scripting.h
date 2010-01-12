#ifndef SCRIPTING_H
#define SCRIPTING_H

#include "interpreter.h"

void gmScriptInit();

/*
*
*een lijst met namen (vector names);
*en een lijst met addressen (vector addresses);
*
*varInt var = 5;
*en dan binnenin gebeurd:
*
*
*
*
*
*
*varInt& operator=(const int &val)
*{
*
*	*addresses[Index] = val;
*}
*
*
*
*
*
*
*
*/
#endif