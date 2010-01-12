#include "theme.h"



theme* blueWindow;
theme* greenWindow;
theme* textureWindow;


theme::theme()
{
	
}

theme::theme(char* fileGUIWindow, char* fileGUIBar)
{
	useTextures = true;
	window.windowText = new texture(fileGUIWindow);
	bar.barText = new texture(fileGUIBar);
}

theme::theme(float windowBottomColor[],float windowTopColor[],float barBottomColor[],float barTtopColor[])
	{
		useTextures = false;
		window.bottomColor[0] = windowBottomColor[0], window.bottomColor[1] = windowBottomColor[1] ,window.bottomColor[2] = windowBottomColor[2], window.bottomColor[3] = 0.95;
		window.topColor[0] = windowTopColor[0], window.topColor[1] = windowTopColor[1], window.topColor[2] = windowTopColor[2], window.topColor[3] = 0.95;
		bar.bottomColor[0] = barBottomColor[0], bar.bottomColor[1] = barBottomColor[1], bar.bottomColor[2] = barBottomColor[2],  bar.bottomColor[3] = 0.95;
		bar.topColor[0] = barTtopColor[0], bar.topColor[1] = barTtopColor[1], bar.topColor[2] = barTtopColor[2],  bar.topColor[3] = 0.95;
	
}

void themeInit()
{	
/*blauw
*/
float wbc[3] = {0.1,0.4,0.7};
float wtc[3] = {0.2,0.1,0.5};
float btc[3] = {0.8,0.6,0.6};
float bbc[3] = {0.95,0.1,0.1};

blueWindow = new theme(wbc,wtc,bbc,btc);
/*groen
*/
float wbc1[3] = {0.1,0.5,0.4};
float wtc1[3] = {0.2,0.7,0.1};

greenWindow = new theme(wbc1,wtc1,bbc,btc);
/*texture
*/
textureWindow = new theme("data/GUI/window.bmp","data/GUI/bar.bmp");
}


