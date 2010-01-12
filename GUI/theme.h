#ifndef WINDOW_OPT_H
#define WINDOW_OPT_H

#include "../image/img.h"

class theme
{
public:
	bool test;
	struct Window
	{
		float bottomColor[4];
		float topColor[4];
		texture* windowText;
	}window;
	struct Bar
	{
		float bottomColor[4];
		float topColor[4];
		texture* barText;
	}bar;
	bool useTextures;


	theme();
	theme(char* fileGUIWindow, char* fileGUIBar);
	theme(float windowBottomColor[],float windowTopColor[],float barBottomColor[],float barTtopColor[]);
};

void themeInit();

extern theme* blueWindow;
extern theme* greenWindow;
extern theme* textureWindow;

#endif