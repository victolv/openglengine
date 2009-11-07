#include <iostream>
#include <gl/glew.h>
#include <gl/glut.h>
#include <gl/gl.h>
#include "simpleGUI.h"

using namespace std;

//bool basicElem::remake()
//{
//	return true;
//}
/*bool basicElem::make()
{
	for(int i = 0;i < sizeX;i++)
	{
		for(int k = 0;k < sizeY;k++)
		{

			ourTexture[k * 3 + i + 0] = 50;
			ourTexture[k * 3 + i + 1] = 50;
			ourTexture[k * 3 + i + 2] = 150;

		}
	}
	return true;
}*/
basicElem::~basicElem()
{
	delete[] texture;
}

basicElem::basicElem(float possitionX, float PossitionY, float width, float height)
{
	cout << "works";
	posX = possitionX;
	posY = PossitionY;
	sizeX = width;
	sizeY = height;
	nextElem = 0;
	focus = false;
}

bool basicElem::isUnderMouse()
{
	if(Mouse.getX() >= posX &&
		Mouse.getY() >= posY &&
		Mouse.getX() <= posX + sizeX &&
		Mouse.getY() <= posY + sizeY)
		return true;
	else return false;
}
bool basicElem::isUnderMousePressed()
{
	if(Mouse.pressedX() >= posX &&
		Mouse.pressedY() >= posY &&
		Mouse.pressedX() <= posX + sizeX &&
		Mouse.pressedY() <= posY + sizeY)
		return true;
	else return false;
}
bool basicElem::isUnderMouseReleased()
{
		if(Mouse.releasedX() >= posX &&
		Mouse.releasedY() >= posY &&
		Mouse.releasedX() <= posX + sizeX &&
		Mouse.releasedY() <= posY + sizeY)
		return true;
	else return false;

}


	//bool createButton(int possitionX = 5, int possitionY = 5, int width = 5, int height = 5, char * test, bool (*onClickFunction)());

	float basicElem::getX()
	{
		return posX;
	}
	float basicElem::getY()
	{
		return posY;
	}
	void basicElem::setX(float x)
	{
		posX = x;
	}
	void basicElem::setY(float y)
	{
		posX = y;
	}

void basicElem::ourTexture()
{
	glColor4f(1,1,0.5,0.75);
}


void basicElem::move(int X, int Y)
{
	posX = X + posX;
	posY = Y + posY;
}
void basicElem::scale(int X, int Y)
{
	sizeX += X;
	sizeY += Y;
}



void basicElem::handleKey(char key)
{
}
void basicElem::handleMouse(int x, int y, int status)
{
}