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
	std::cout << a << "AND, " << b << std::endl;
}

void initTest(){

int tempa[2] = {INT,INT};
function GMSasdf(asdf,tempa,2,VOID,"asdf");
dataType* temp[2];
temp[0] = new dataType(1);
temp[1] = new dataType(2);

dataType var1 = 1;
dataType var2 = 2;

std::cout << &var1 << "\t" << &var2 << std::endl;

GMSasdf.exec(&var1,&var2);
//GMSasdf.exec(temp);
//DevHC @ Freenode
}