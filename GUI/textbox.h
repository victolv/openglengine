#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "basicElem.h"
#include <string.h>

class textbox : public basicElem
{
private:
	std::string text;
		int count;
		int cursorPlace;	//waar moeten we de cursor drawen?
		int selectXBeg, selectXEnd;
		int recSelect;
		int _select_lastClickedX,_select_lastClickedY;
		float fontSize;
public:
	const char* getString();
	void getString(char* theString);

	int getInt();
	void getInt(int* theInt);
										
	float getFloat();
	void getFloat(float* theFloat);


	void render();
	void update();
		textbox();

	void handleKey(char key);
};

#endif