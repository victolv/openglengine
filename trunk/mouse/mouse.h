#ifndef MOUSE_H
#define MOUSE_H

#define LEFT_BUTTON 0
#define MIDDLE_BUTTON 1
#define RIGHT_BUTTON 2

#define BUTTON_DOWN 1
#define BUTTON_UP 0

class mouse
{
private:
	int x, y;
	int diffy, diffx;
	bool LMB;
	bool RMB;
	bool MMB;
	int pressedx, pressedy;
	int releasedx, releasedy;

	
	friend void clickHandle(int button, int state, int x, int y);
protected:
public:
	int releasedX();
	int releasedY();
	int getX();
	int getY();
	int getdiffY();
	int getdiffX();
	bool pressedLMB();
	bool pressedRMB();
	bool pressedMMB();
	int pressedX();
	int pressedY();
	void setXY(int X, int Y);
	void calcChangeX();
	void calcChangeY();
	void clickHandle(int button, int state, int x, int y);
	void mouseMovement(int X, int Y);

};

void clickHandle(int button, int state, int x, int y);
void mouseMovement(int X, int Y);


extern mouse Mouse;
#endif