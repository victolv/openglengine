#ifndef MOUSE_APPS_H
#define MOUSE_APPS_H


class mouseApps
{
private:
	int x,y;
	int diffX,diffY;
	int xOld,yOld; 
public:
	mouseApps();
	void update();
	void reset();
	int getDiffY();
	int getDiffX();
};
#endif