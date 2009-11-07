#ifndef RANDOM_H
#define RANDOM_H
#include <iostream>
class Random
{
public:
Random();
template<class var1> var1 gen(var1 min, var1 max){
	return min + rand() % (max + 1 - min);
}
template<class var2> void gen(var2 min, var2 max,int ammount, var2* theArray){
	for(int i = 0;i < ammount;i++){
	theArray[i] = min + rand() % (max + 1 - min);
	}
}

void gen(float min, float max,int ammount, float *theArray);
float gen(float min, float max);
double gen(double min, double max);

};

extern Random random;
#endif