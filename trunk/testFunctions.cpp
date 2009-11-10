#include <iostream>

#include "gmScript/dataTypes.h"
#include "gmScript/func.h"

using namespace std;

void Exit()
{
	exit(1);
}

void asdf(int a, int b)
{
	std::cout << a << " AND, " << b << std::endl;
}
void asdf1(int a, int b, int c, int d)
{
	std::cout << a << ", " << b << ", " << c << ", " << d << std::endl;
}

void initTest(){

int tempa[2] = {INT,INT};
int tempb[] = {INT,INT,INT,INT};
function GMSasdf(asdf,tempa,2,VOID,"asdf");
function GMSasdf1(asdf1,tempb,4,VOID,"asdf1");
dataType* temp[2];

dataType var1 = 1;
dataType var2 = 255;
dataType var3 = 135;
dataType var4 = 155;

dataType* dataPointer[] =
{&var1, &var2};

dataType* dataPointer1[] =
{&var2, &var1,&var3,&var4};


std::cout << &var1 << "\t" << &var2 << std::endl;

GMSasdf.exec(dataPointer);
GMSasdf1.exec(dataPointer1);
//GMSasdf.exec(temp);
//DevHC @ Freenode
}