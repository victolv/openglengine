#include <iostream>
#include <gl/gl.h>
#include <gl/glut.h>
#include <IL/il.h>
#include "button.h"
#include "text/font.h"
#include "../mouse/mouse.h"

button::button(float x, float y,float width, float height,char* Text, void (*onClick)()) : basicElem(x,y,width,height)
{
	onLMBClick = onClick;
	text = Text;
	clickOnce = false;
}
button::button(float width, float height, char* Text, void (*onClick)()) : basicElem(0,0,width,height)
{
	onLMBClick = onClick;
	text = Text;
	clickOnce = false;
}
button::button(char* Text, void (*onClick)()) : basicElem(0,0,60,20)
{
	onLMBClick = onClick;
	text = Text;
	clickOnce = false;
}
void button::ourColor()
{
	if(isUnderMouse())
	glColor3f(0.5,0.5,0.6);
	else
	glColor3f(0.4,0.4,0.5);
}

void button::update()
{
	if(isUnderMousePressed())
	{
		if(!Mouse.pressedLMB() && isUnderMouseReleased() && clickOnce == false)
		{
			onLMBClick();
			clickOnce = true;
		}
		else if(Mouse.pressedLMB())
			clickOnce = false;
	glColor3f(0.5,0.5,0.6);
	}
	else
		release = true;
	glColor3f(0.4,0.4,0.5);
}
void button::render()
{	ourColor();

	glBegin(GL_QUADS);
	glVertex2f(posX,posY);
	glVertex2f(posX,posY + sizeY);
	glVertex2f(posX + sizeX,posY + sizeY);
	glVertex2f(posX + sizeX,posY);
	glEnd();

	glColor4f(1,0.0,0.0,0.8);
	timesRoman.render(posX +5, posY + sizeY / 2,text);
}

