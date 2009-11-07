#include "mouse.h"
#include <iostream>


mouse Mouse;
int mouse::getX()
{
return x;
}
int mouse::getY()
{
	return y;
}
int mouse::getdiffY()
	{
		static int lasty = y;
		diffy = y - lasty;
		lasty = y;
		return diffy;
	}
int mouse::getdiffX()
{
		static int lastx = x;
		diffx = x - lastx;
		lastx = x;
		return diffx;
}

void mouse::setXY(int X, int Y)
{
	x = X;
	y = Y;
	std::cout << x << "\t" << y << std::endl;
}

bool mouse::pressedLMB()
	{
		return LMB;
	}
bool mouse::pressedRMB()
	{
		return RMB;
	}
bool mouse::pressedMMB()
	{
		return MMB;
	}


void mouse::mouseMovement(int X, int Y)
{
	Mouse.setXY(X,Y);
	Mouse.calcChangeX();
	Mouse.calcChangeY();
}

void mouse::clickHandle(int button, int state, int x, int y)
{
	switch(button)
	{
		case 1:
	LMB = state % 3;		// LINKER MUIS KNOP
	break;
		case 2:
	MMB = state % 3 ;
		case 3:
	RMB = state % 3;
	break;
	}
	switch(state)
	{
	case 5:
		pressedx = x;
		pressedy = y;
		break;
	case 6:
		releasedx = x;
		releasedy = y;
		break;

	}

}

int mouse::pressedX()
	{
		return pressedx;
	}
int mouse::pressedY()
	{
		return pressedy;
	}

int mouse::releasedX()
{
	return releasedx;
}
int mouse::releasedY()
{
	return releasedy;
}
void mouse::calcChangeX()
{
static int lastx;
 diffx=x-lastx;
lastx=x;
}
void mouse::calcChangeY()
{
static int lasty;
diffy=y-lasty;
lasty=y;
}
