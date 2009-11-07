#include "random.h"

#include <stdio.h>
#include <windows.h>

Random::Random()
{
	srand(GetTickCount());
}

void Random::gen(float min, float max,int ammount, float *theArray)
{
	float newMin = min * 10000;
	float newMax = max * 10000;
	for(int i = 0;i < ammount;i++)
	{
	theArray[i] = float(int(newMin + rand() * 10000) % int(newMax + 1 - newMin))/10000 + min;
	}
}
float Random::gen(float min, float max)
{
	float newMin = min * 10000;
	float newMax = max * 10000;
	return float(int(newMin + rand() * 10000) % int(newMax + 1 - newMin))/10000 + min;
}
double Random::gen(double min, double max)
{
	double newMin = min * 10000;
	double newMax = max * 10000;
	return double(int(newMin + rand() * 10000) % int(newMax + 1 - newMin))/10000 + min;
}
Random random;