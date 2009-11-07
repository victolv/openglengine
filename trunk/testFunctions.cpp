#include <iostream>

#include "gmScript/dataTypes.h"
#include "gmScript/functions.h"

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

GMSasdf.exec(1,2);
//GMSasdf.exec(temp);
//DevHC @ Freenode
}