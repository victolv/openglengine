#include "mouseApps.h"
#include "mouse.h"

mouseApps::mouseApps()
{
	x = Mouse.getX();
	y = Mouse.getY();
	xOld = x;
	yOld = y;
}


void mouseApps::update()
{
		diffY = y - yOld;
		diffX = x - xOld;

	yOld = y;
	xOld = x;



	x = Mouse.getX();
	y = Mouse.getY();

}

void mouseApps::reset()
{
	yOld = Mouse.getY();
	xOld = Mouse.getX();
	x = Mouse.getX();
	y =Mouse.getY();
}


int mouseApps::getDiffY()
{
	return diffY;
}
int mouseApps::getDiffX()
{
	return diffX;
}