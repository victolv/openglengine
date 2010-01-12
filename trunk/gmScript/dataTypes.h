#ifndef DATATYPES_H
#define DATATYPES_H

#include <string>
#include <list>
#include <vector>

#define MEND 0
#define MVOID 1
#define MINT 2
#define MFLOAT 3
#define MDOUBLE 4
#define MCHAR 5
#define MCHARP 6
#define MUNKNOWN 60

class data{
public:
const char* name; 
};


class dataType : public data{
public:
int index;
public:
int size;
int type;
void* var;

bool isConst;

//dataType(char value);
dataType(int value);
dataType(int value, const char* name);
dataType(char* value);
dataType(char* value, const char* name);
dataType(void* value);
dataType(void* value, const char* name);
dataType& operator=(const int value);
dataType& operator=(const char* value);
dataType& operator=(const dataType value);
//dataType& operator=(const void* value);
};
dataType* findVar(const char* name);
int GMSsizeof(int type);
char* getTypeName(dataType* var);


extern std::list<dataType*> variables;



/*
class dataTypeObject : public dataType
{
	varFloat();
	dataType& operator=(int val);
}
*/


#endif