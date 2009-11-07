#include "colorPicker.h"

#include <GL/gl.h>
	
colorPicker::colorPicker(int *colorpointer) :  basicElem(0,0,200,200)
{
	colorPointer = colorpointer;
	color.colorLeftBottom[0] = INT_MAX; color.colorLeftBottom[1] = 0; color.colorLeftBottom[2] = 0;
	color.colorLeftTop[0] = 0; color.colorLeftTop[1] = INT_MAX; color.colorLeftTop[2] = 0;
	color.colorRightBottom[0] = 0; color.colorRightBottom[1] = 0; color.colorRightBottom[2] = INT_MAX;
	color.colorRightTop[0] = INT_MAX; color.colorRightTop[1] = INT_MAX; color.colorRightTop[2] = INT_MAX;
} 
void colorPicker::render()
{
	glBegin(GL_QUADS);
	glColor3iv(color.colorLeftTop);
	glVertex2f(posX, posY);
	glColor3iv(color.colorRightTop);
	glVertex2f(posX + sizeX, posY);
	glColor3iv(color.colorRightBottom);
	glVertex2f(posX + sizeX, posY + sizeY);
	glColor3iv(color.colorLeftBottom);
	glVertex2f(posX,posY + sizeY);
	glEnd();
}
void colorPicker::update()
{

}