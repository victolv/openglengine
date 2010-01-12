#include "dye.h"
#include <string>
#include <iostream>

#define DYENUM 13

int color[3];
int colors[][3] = 
{
		255, 255, 255,
		31, 31, 31,
		0, 0, 0,
		0, 255, 255,
		0, 127, 127,
		255, 0, 0,
		127, 0, 0,
		255, 0, 25,
		255, 127, 0,
		255, 255, 0,
		127, 127, 0,
		0, 255, 0,
		0, 127, 0,
		79, 61, 23
};
char names[][15] = 
{
		"Bleach",
		"Black",
		"PBlack",
		"BCyan",
		"Cyan",
		"BRed",
		"Red",
		"Magenta",
		"Orange",
		"BYellow",
		"Yellow",
		"BGreen",
		"Green",
		"Brown"
};
char namePointer[100];
dyecalc dyeCalc;


void dyecalc::update(int R, int G, int B)
{
color[0] = R;
color[1] = G;
color[2] = B;
std::cout << R << ", " << G << ", " << B << std::endl;
}

void dyecalc::calc()
{
	for(;;){
		if(trycolor[0] + 20 > color[0] || trycolor[0] - 20 < color[0]
		&& trycolor[1] + 20 > color[1] || trycolor[1] - 20 < color[1]
		&& trycolor[2] + 20 > color[2] || trycolor[2] - 20 < color[2])
		{
			//take first dye
			for(int i = 0;i < DYENUM;i++){
			i 
			}

		}

}






























	/*
	namePointer[0]  = names[11][0];
	int trycolor[3] = {127, 127, 0}; //start with yellow, default
	int tempcolor[3] = {0, 0, 0};
	int tempcolorBest[3] = {0, 0, 0};

	for(int i = 0;i < 9999999;i++)
	{
		if(trycolor[0] + 20 > color[0] || trycolor[0] - 20 < color[0]
		&& trycolor[1] + 20 > color[1] || trycolor[1] - 20 < color[1]
		&& trycolor[2] + 20 > color[2] || trycolor[2] - 20 < color[2])
		{
			for(int i = 0;(colors[0] - tempcolorBest[0]) > (colors[0] - tempcolor[0])
			||
			(-(colors[i][0] - tempcolorBest[0]) > (colors[i][0] - tempcolor[0]))
			&&				
			(colors[i][1] - tempcolorBest[1]) > (colors[i][1] - tempcolor[1])
			||
			(-(colors[i][1] - tempcolorBest[1]) > (colors[i][1] - tempcolor[1]))
			&&
			(colors[i][2] - tempcolorBest[2]) > (colors[i][2] - tempcolor[2])
			||
			(-(colors[i][2] - tempcolorBest[2]) > (colors[i][2] - tempcolor[2])); i++)	// ooh sexy
			{
				tempcolor[0] = colors[0][i];
				tempcolor[1] = colors[1][i];
				tempcolor[2] = colors[2][i];
			}	

		}  	
	}
}

void dyeCalcWrapper()
{
	dyeCalc.calc();
}*/