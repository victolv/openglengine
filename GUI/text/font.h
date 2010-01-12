#ifndef FONT_H
#define FONT_H

#include <iostream>
#include "../../image/img.h"

class font
{
public:
	char* fileName;
	texture fontIMG;
	int base;
	float size;
	font(char* file);
	font();
	void load(char* file);
	void render(float x, float y, const char *text);
	void render(float x, float y, const char *text, float size);
	~font();
};

extern font timesRoman;
#endif