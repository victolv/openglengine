#ifndef COLORPICKER_H
#define COLORPICKER_H
#include "basicElem.h"

class colorPicker : public basicElem
{
public:
	struct Color{
	int colorLeftBottom[3];
	int colorLeftTop[3];
	int colorRightBottom[3];
	int colorRightTop[3];
	}color;
	int *colorPointer;
	colorPicker(int *colorpointer);
	void render();
	void update();

	
};
#endif