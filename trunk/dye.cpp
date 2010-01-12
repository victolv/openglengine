#include "dye.h"
#include <string>
#include <iostream>
int color[3];
int range = 20;

int colors[][3] = 
{
		0, 127, 127,
		31, 31, 31,
		0, 255, 255,
		255, 0, 25,
		255, 127, 0,
		255, 255, 0,
		127, 127, 0,
		0, 255, 0,
		0, 127, 0,
		79, 61, 23,
		0, 0, 127,
		0, 0, 255,
		127, 0, 0,
		255, 0, 0,
		0, 0, 0,
		255, 255, 255
};
char names[][15] = 
{
		"Cyan\0",
		"Black\0",
		"BCyan\0",
		"Magenta\0",
		"Orange\0",
		"BYellow\0",
		"Yellow\0",
		"BGreen\0",
		"Green\0",
		"Brown\0",
		"Blue\0",
		"BBlue\0",
		"Red\0",
		"BRed\0",
		"PBlack\0",
		"Bleach\0"
};
dyecalc dyeCalc;


void dyecalc::update(int R, int G, int B)
{
color[0] = R;
color[1] = G;
color[2] = B;
std::cout << R << ", " << G << ", " << B << std::endl;
}


	char *namePointer[100];
	int trycolor[3] = {0, 0, 0}; //
	int tempcolor[3] = {colors[0][0], colors[0][1], colors[0][2]};
	int dyeAm = 0;


void dyecalc::calc()
{
//try to get nearer to wished RGB
	
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


	
	
	/*int k = 0;
		if(!(k < 16))
			k = 0;

		trycolor[0] = 999;
		trycolor[1] = 999;
		trycolor[2] = 999;
for(int retry = 0;retry < 100;retry++)// start with different dye

{			tempcolor[0] = colors[retry][0];
			tempcolor[1] = colors[retry][1];
			tempcolor[2] = colors[retry][2];
			trySucces();
			

			trycolor[0] = 999;
			trycolor[1] = 999;
			trycolor[2] = 999;						

		for(int l = 0;l < 16;l++)//change second mix dye
		{/*
			tempcolor[0] = colors[l][0];
			tempcolor[1] = colors[l][1];
			tempcolor[2] = colors[l][2];
		

			for(int i = 0;namePointer[i];i++)
			namePointer[i] = 0;
			namePointer[0] = names[l];
			dyeAm = 0;

		for(int j = 0;j < 2;j++) //max ammount of dyes
		{

			for(int i = 0+l;i < 16;i++) //try 16 dye possibilities
			{ 
				tempcolor[0] = (colors[i][0] + tempcolor[0])/2;
				tempcolor[1] = (colors[i][1] + tempcolor[1])/2;
				tempcolor[2] = (colors[i][2] + tempcolor[2])/2;
				{
					if((diference(tempcolor[0],color[0]) <= diference(trycolor[0],color[0]))||
						(diference(tempcolor[1],color[1]) <= diference(trycolor[1],color[1]))||
						(diference(tempcolor[2],color[2]) <= diference(trycolor[2],color[2])))
					{
						if(diference3(tempcolor,color) < diference3(trycolor,color))
						{
						trycolor[0] = tempcolor[0];
						trycolor[1] = tempcolor[1];
						trycolor[2] = tempcolor[2];
						namePointer[j] = names[i];
						dyeAm++;
						trySucces();
						//i++;
						}
					}
					else if(i >= 16)
					{
						for(int i = 0;i < dyeAm;i++)
						namePointer[i] = 0;
					
						//dyeAm = 0;
					}

					else
					{
						//i++;
						tempcolor[0] = trycolor[0];
						tempcolor[1] = trycolor[1];
						tempcolor[2] = trycolor[2];//tempcolor?..
					}
				}
			}
		}
		if(k > 16)
		k = 0;
		else k++;
		}
		trySucces();
}
		trySucces();

}
*/

bool trySucces()
{
	
		if(trycolor[0] + range > color[0] && trycolor[0] - range < color[0]
		&& trycolor[1] + range > color[1] && trycolor[1] - range < color[1]
		&& trycolor[2] + range > color[2] && trycolor[2] - range < color[2])//if in radius
		{
			for(int i = 0;i <= dyeAm;i++)
			{
				for(int i = 0;namePointer[i];i++)
				std::cout << namePointer[i] << ",\n";
			}
			return true;
		}
		else return false;
}




void dyeCalcWrapper()
{
	dyeCalc.calc();
}

int diference(int a, int b)
{
	a = a - b;
	if(a < 0)
		a = -a;
	return a;
}

int diferenceAvg3(int* a, int* b)
{
	int dif = 0;
	//for(int i = 0;i < 3;i++)
	dif += a[0] + b[0];
	dif += a[1] + b[1];
	dif += a[2] + b[2];

	dif /=3;


	return dif;
}
int diference3(int* a, int* b)
{
	int dif = 0;
	dif += a[0] - b[0];
	dif += a[1] - b[1];
	dif += a[2] - b[2];

	if(dif < 0)
		dif = -dif;

	return dif;
}
int temp[3];

int* mixDye(int* dye1,int* dye2)
{
	temp[0] = (dye1[0] + dye2[0]);
	temp[1] = (dye1[1] + dye2[1]);
	temp[2] = (dye1[2] + dye2[2]);
	return temp;
}
