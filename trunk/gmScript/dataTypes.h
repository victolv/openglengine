#ifndef DATATYPES_H
#define DATATYPES_H

#include <string>
#include <list>
#include <vector>

#define END 0
#define VOID 1
#define INT 2
#define FLOAT 3
#define CHAR 4
#define UNKNOWN 60

class dataType{
public:
int index;
public:
int size;
int type;
const char* name;
void* var;
//dataType(char value);
dataType(int value);
dataType(int value, const char* name);
dataType(void* value);
dataType(void* value, const char* name);
dataType& operator=(const int value);
dataType& operator=(const char* value);
dataType& operator=(const dataType value);
//dataType& operator=(const void* value);
};
dataType& findVar(const char* name);

extern std::list<dataType> variables;


/*
class dataTypeObject : public dataType
{
	varFloat();
	dataType& operator=(int val);
}
*/


#endif