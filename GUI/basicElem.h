#ifndef BASICELEM_H
#define BASICELEM_H

#include "../mouse/mouse.h"
#include "../image/img.h"
#include "text/font.h"

class basicElem
{
protected:
	friend class gui;
	friend class guiList;
	void setX(float x);
	void setY(float y);
	float posX, posY;
	float sizeX, sizeY;
	bool isUnderMouse();
	bool isUnderMousePressed();
	bool isUnderMouseReleased();
	void move(int X, int Y);
	void scale(int X, int Y);
	bool focus;
	virtual void handleKey(char key);
	virtual void handleMouse(int x, int y, int status);

public:
	bool vissible;
	unsigned char * texture;
	basicElem* nextElem;
	
	float getX();
	float getY();
	void ourTexture();
	basicElem(float possitionX, float PossitionY, float width, float height);
	~basicElem();	//delete our texture information.
	virtual void render() = 0;	//draw on screen
	virtual void update() = 0; //update
	//void input();
	void onFocus();

	
};

#endif 

