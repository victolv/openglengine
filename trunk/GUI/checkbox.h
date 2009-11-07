#ifndef CHECKBOX_H
#define CHECKBOX_H
#include "basicElem.h"

class checkbox : public basicElem
{
private:
	bool* State;
protected:
public:
	checkbox(int x, int y, int width, int height, bool& state);
	checkbox(int x, int y, bool& state);
	checkbox(bool& state);
	void update();
	void render();
	bool getState();
};
#endif