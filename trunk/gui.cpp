#include <iostream>
#include <sstream>
#include <gl/gl.h>
#include <list>
#include "gui.h"
#include "../screen/resize.h"
#include "text/font.h"
#include "../mouse/mouseApps.h"

using namespace std;
gui::gui(float possitionX , float PossitionY, float width, float height, char* Text, theme* Options) :  basicElem(possitionX,PossitionY,width,height)
{
	text = Text;
	applyMove = false;
	autoSize = false;
	options = Options;
	focusedOne = this;

}
gui::gui(float possitionX, float PossitionY, float width, float height, char* Text) : basicElem(possitionX,PossitionY,width,height)
{
	text = Text;
	applyMove = false;
	autoSize = false;
	options = blueWindow;
	focusedOne = this;
}

gui::gui(float possitionX , float PossitionY, char* Text, theme* Options) : basicElem(possitionX,PossitionY,0,0)
{
	autoSize = true;
	text = Text;
	options = Options;
	focusedOne = this;

}
gui::gui(float possitionX , float PossitionY, char* Text) : basicElem(possitionX,PossitionY,0,0)
{
	autoSize = true;
	text = Text;
	options = blueWindow;
	focusedOne = this;
}
gui::gui(char* Text, theme* Options) : basicElem(200,200,0,0)
{
	autoSize = true;
	text = Text;
	options = Options;
	focusedOne = this;
}
gui::gui(char* Text) : basicElem(200,200,0,0)
{
	autoSize = 0;
	text = Text;
	options = blueWindow;
	focusedOne = this;
}
gui::gui(theme* Options) : basicElem(200,200,0,0)
{
	autoSize = true;
	text = "\0";
	options = Options;
	focusedOne = this;
}

gui::gui() : basicElem(200,200,0,0)
{

	autoSize = true;
	text = "\0";
	options = blueWindow;
	focusedOne = this;
}
bool gui::newElem(basicElem * newElement)
{
	if(focusedOne == this)
	{// is dit de eerste van window?
		focusedOne = newElement;
 		newElement->posY += 5;
		scale(newElement->sizeX + 5,0);
		elems.push_back(newElement);
		return true;//zoja dan hoeft er niks worden berekent.
	}



	if(!elems.empty())
	{//als list niet leeg is
		//neem de laatste

		std::list<basicElem>::iterator it = elems.end();
			it--;
				newElement->move(0,(*elems.end())->posY + (*elems.end())->sizeY + 5);
				scale(0,(*elems.end())->posY - (*elems.end())->sizeY);
	
/*

		if(tempY > posY + sizeY - 5 && autoSize)
			scale(0,newElement->sizeY +  50);

		if(newElement->sizeX+newElement->posX  > posX + sizeX && autoSize)
			scale(newElement->sizeY + 20,0);

*/

	newElement->move(posX + 10, 0);


	elems.push_back(newElement);
		return true;
}

bool gui::mouseUnderBar()
{
	if(Mouse.getX() >= posX &&
		Mouse.getY() >= posY - 20 &&
		Mouse.getX() <= posX + sizeX &&
		Mouse.getY() <= posY)

		return true;


	else return false;
}


void gui::update()
{

				if(focusedOne && !focusedOne->isUnderMousePressed())
					focusedOne->focus = false;


	if(isUnderMousePressed())
	{

		for(list<basicElem*>::iterator current = elems.begin();current != elems.end();current++)
		{
	
			if((*current)->isUnderMousePressed())
			{
				(*current)->focus = true;
				focusedOne = (*current);
			}
							focusedOne->update();

		}
		//our update function
		//lets make our window move-able
	}

		if(Mouse.pressedLMB() && applyMove)
		{
		mouseHelper.update();
		posX += mouseHelper.getDiffX();
		posY += mouseHelper.getDiffY();
		/////////////////
		for(list<basicElem*>::iterator current = elems.begin();current != elems.end();current++)
		{
			(*current)->move(mouseHelper.getDiffX(), mouseHelper.getDiffY());
		}
////////////////////////
		}
		else
		{
			mouseHelper.reset();
			checkMove();
		}

}



void gui::checkMove()
{		
	if(mouseUnderBar())
	{
		if(Mouse.pressedLMB())
		{
			applyMove = true;
		}
	}
	else applyMove = false;
}



void gui::render()
{

	glDisable(GL_LIGHTING);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0,getWindowWidth(),getWindowHeight(),0,0,1);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glPushAttrib(GL_CURRENT_BIT);
		glLoadIdentity();
		if(options->useTextures){
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,options->window.windowText->ID);
		}
		else
		glColor4fv(options->window.topColor);

		glBegin(GL_QUADS);
		glTexCoord2f(0,1);	glVertex2f(posX,posY);
		glTexCoord2f(1,1);	glVertex2f(posX + sizeX, posY);
		if(!options->useTextures) glColor4fv(options->window.bottomColor);
		glTexCoord2f(1,0);	glVertex2f(posX + sizeX, posY + sizeY);
		glTexCoord2f(0,0);	glVertex2f(posX, posY + sizeY);
		glEnd();

		if(options->useTextures)
			glBindTexture(GL_TEXTURE_2D,options->bar.barText->ID);
		else
		glColor4fv(options->bar.topColor);
		glBegin(GL_QUAD_STRIP);

		glTexCoord2f(1,0);	glVertex2f(posX,posY);
		glTexCoord2f(0,0);	glVertex2f(posX + sizeX, posY);

		glTexCoord2f(0,25); glVertex2f(posX, posY - 5);
		glTexCoord2f(0,25); glVertex2f(posX + sizeX, posY - 5);

		if(!options->useTextures) glColor4fv(options->bar.bottomColor);
		glTexCoord2f(1,1);	glVertex2f(posX, posY - 20);
		glTexCoord2f(0,1);	glVertex2f(posX + sizeX, posY - 20);
		glEnd();
		glDisable(GL_TEXTURE_2D);

		for(list<basicElem*>::iterator current = elems.begin();current != elems.end();current++)
		{
			//if((*current)->isUnderMouse())
			//	glColor3f(0,1,0);
			(*current)->render();
		}

		glColor4f(1,0,0,1);
		timesRoman.render(posX + 5,posY - 6,text);

		if(enableDebug)
		{
			std::stringstream numberxyz;
			glColor4f(0,8.8,0,0.7);
			if(debug.printCoords)
			{
			numberxyz << (int)posX << ',' << (int)posY << '\0';
			timesRoman.render( posX,posY,const_cast<char*>(numberxyz.str().c_str()));
			}
			if(debug.printx)
			{
				numberxyz.str("");
				numberxyz << sizeX << '\0';
				timesRoman.render(posX+sizeX/2,posY,const_cast<char*>(numberxyz.str().c_str()));
			}
				if(debug.printy)
			{
				numberxyz.str("");
				numberxyz << sizeY << '\0';
				timesRoman.render(posX,posY+sizeY/2,const_cast<char*>(numberxyz.str().c_str()));
				numberxyz.str("");
			}
		}
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPopMatrix();
		glPopAttrib();
		glDisable(GL_LIGHTING);
return;
}

void gui::handleKey(char key)
{
	if(focusedOne != this && focusedOne)
	focusedOne->handleKey(key);
}
void gui::handleMouse(int x, int y, int status)
{
	if(focusedOne != this && focusedOne)
	focusedOne->handleMouse(x,y, status);
}




/*/////////////////////////////////////////////////////////////////
/*GUILIST!
/*
/*////////////////////////////////////////////////////////////////

void guiList::add(gui* theGUI)
{
	guilist.push_back(theGUI);
	theGUI->focus = true;
	if(guilist.size() > 1)
	(*(guilist.end()-2))->focus = false;
}
void guiList::dissable(gui* theGUI)
{
	return;
}
void guiList::enable(gui* theGUI)
{
	return;
}
void guiList::remove(gui* theGUI)
{
	vector<gui*>::iterator it = guilist.begin();
	for(it;it != guilist.end();it++)
	{
		if(*it == theGUI)
		guilist.erase(it);
	}
}

void guiList::renderAll()
{
	vector<gui*>::iterator it = guilist.begin();
	for(it;it != guilist.end();it++)
	{
		(*it)->render();
	}
}

void guiList::updateAll()
{
	vector<gui*>::iterator it = guilist.begin();
	for(it;it != guilist.end();it++)
	{
		if((*it)->focus)
		{
		(*it)->update();
		
		}

		if((*it)->focus == false && (*it)->isUnderMousePressed())
		{
			(*it)->focus = true;
			(*(guilist.end()-1))->focus = false;
			gui* it2  = *it;
			guilist.erase(it);
			guilist.push_back(it2);
//			std::swap(*it,*(guilist.end()-1));
			break;
		}
	}
}


void guiList::handleKey(char key)
{
	(*(guilist.end()-1))->handleKey(key);

}
void guiList::handleMouse(int x, int y, int status)
{
	(*(guilist.end()-1))->handleMouse(x,y, status);
}

guiList GUIList;