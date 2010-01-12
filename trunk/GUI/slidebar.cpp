#include "slidebar.h"
#include "../mouse/mouse.h"

#include <GL/gl.h>
//
#include <iostream>
//Temp, alleen ff testen of de waarden goed zijn.
slidebar::slidebar(int x, int y, int width, int height,float beginNum, float endNum, float& Value) : basicElem(x,y,width,height)
{
beginNumber = beginNum;
endNumber = endNum;
valuePos = sizeX / endNumber;
value = &Value;
}
slidebar::slidebar(int x, int y, float beginNum, float endNum,float& Value) : basicElem(x,y,100,50)
{
beginNumber = beginNum;
endNumber = endNum;
valuePos = sizeX / endNumber;
value = &Value;
}
slidebar::slidebar(int width, float beginNum, float endNum, float& Value) :  basicElem(0,0,width,50)
{
beginNumber = beginNum;
endNumber = endNum;
valuePos = sizeX / endNumber;
value = &Value;
}
slidebar::slidebar(float beginNum, float endNum, float& Value) : basicElem(0,0,100,50)
{
beginNumber = beginNum;
endNumber = endNum;
valuePos = sizeX / endNumber;
value = &Value;
}
slidebar::slidebar(float beginNum, float endNum) : basicElem(0,0,100,50)
{
beginNumber = beginNum;
endNumber = endNum;
valuePos = sizeX / endNumber;
ownValue = 0;
value = &ownValue;
}


float slidebar::getValue()
{
	return *value;
}


void slidebar::render()
{

		if(isUnderMouse())
		glColor3f(0.6,0.6,0.65);
		else
		glColor3f(0.3,0.3,0.4);

		glBegin(GL_LINES);
		glVertex2f(posX, posY + sizeY / 2);
		glVertex2f(posX + sizeX, posY + sizeY / 2);

		glVertex2f(posX, posY + sizeY / 2 + 10);
		glVertex2f(posX, posY + sizeY / 2 - 10);

		glVertex2f(posX + sizeX, posY + sizeY / 2 + 10);
		glVertex2f(posX + sizeX, posY + sizeY / 2 - 10);
		glEnd();

		if(Mouse.getX() > posX + valuePos &&
			Mouse.getX() < posX + valuePos + 5 &&
			Mouse.getY() > posY + sizeY / 2 - 5 &&
			Mouse.getY() < posY + sizeY / 2 + 5)
			glColor3f(0.6,0.4,0.1);

		glBegin(GL_QUADS);	
		glVertex2f(posX + valuePos,posY + sizeY / 2 - 5);
		glVertex2f(posX + valuePos + 5,posY + sizeY / 2 - 5);
		glVertex2f(posX + valuePos + 5,posY + sizeY / 2 + 5);
		glVertex2f(posX + valuePos,posY + sizeY / 2 + 5);
		glEnd();



	}

void slidebar::update()
	{
		//*value =  ((sizeX / addNum)/(sizeX/10)) / (sizeX / (Mouse.getX() - posX));
		//niet werkende...
		if(isUnderMouse() && isUnderMousePressed()  && Mouse.pressedLMB())
		{
			float addNum = endNumber - beginNumber;
		
			*value = beginNumber + ((addNum / sizeX) * (Mouse.getX() - posX));


			valuePos = (Mouse.getX() - posX) - 2.5;
			//valuePos = ((sizeX / addNum) * *value) - beginNumber;
			std::cout << *value << std::endl;

		}
	}