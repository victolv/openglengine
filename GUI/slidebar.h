#ifndef SLIDEBAR_H
#define SLIDEBAR_H
#include "basicElem.h"

class slidebar : public basicElem
{
private:
float *value;
float valuePos;
float beginNumber, endNumber;
float ownValue;
public:
	slidebar(int x, int y, int width, int height,float beginNum, float endNum, float& Value);
	slidebar(int x, int y, float beginNum, float endNum, float& Value);
	slidebar(int width, float beginNum, float endNum, float& Value);
	slidebar(float beginNum, float endNum, float& Value);
	slidebar(float beginNum, float endNum);
	float getValue();

	void update();
	void render();

};
#endif