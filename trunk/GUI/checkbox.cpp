#include "checkbox.h"
#include <GL/gl.h>
bool pressed;
checkbox::checkbox(int x, int y,bool& state) :  basicElem(x,y,15,15)
{
	State = &state;
}
checkbox::checkbox(bool& state) :  basicElem(0,0,15,15)
{
	State = &state;
}
checkbox::checkbox(int x, int y, int width, int height,bool& state) :  basicElem(x,y,width,height)
{
	State = &state;
}
bool checkbox::getState()
{
	return State;
}
void checkbox::update()
{
	if(!pressed)
	{
		if(isUnderMousePressed() && !Mouse.pressedLMB() && isUnderMouseReleased())
	{
		pressed = true;

		if(*State)
		*State = false;
		else
		*State = true;
	}
	}
	else
		if(Mouse.pressedLMB())
			pressed = false;
}
void checkbox::render()
{
	if(*State)
	glColor3f(0.7,0.7,1);
	else
	glColor3f(1,1,1);

	glBegin(GL_QUADS);
	glVertex2i(posX, posY);
	glVertex2i(posX + sizeX, posY);
	glVertex2i(posX + sizeX, posY + sizeY);
	glVertex2i(posX, posY + sizeY);
	glEnd();
}