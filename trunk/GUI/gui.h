#ifndef GUI_H
#define GUI_H
#include <list>
#include <vector>
#include "basicElem.h"
#include "theme.h"
#include "..//mouse/mouse.h"
#include "../mouse/mouseApps.h"



class gui : public basicElem
{
private:
	friend class guiList;
	mouseApps mouseHelper;
	std::list<basicElem*> elems;
	char* text;
	bool applyMove;
	bool mouseUnderBar();
	void checkMove();
	basicElem* focusedOne;

public:
	gui(float possitionX , float PossitionY, float width, float height, char* Text, theme* Options);
	gui(float possitionX , float PossitionY, float width, float height, char* Text);
	gui(float possitionX , float PossitionY, char* Text, theme* Options);
	gui(float possitionX , float PossitionY, char* Text);
	gui(char* Text, theme* Options);
	gui(char* Text);
	gui(theme* Options);
	gui();
	void render();
	void update();
	bool newElem(basicElem* newElement);
		//Optiest
	bool autoSize;
	theme* options;

	void handleKey(char key);
	void handleMouse(int x, int y, int status);
/////////////////////////////////////////
	struct guiDebug
	{
		bool printCoords;
		bool printx, printy;
	}debug;
bool enableDebug;
};

class guiList
{
private:
	std::vector<gui*> guilist;
public:
	void add(gui* theGUI);
	void dissable(gui* theGUI);
	void enable(gui* theGUI);
	void remove(gui* theGUI);

	void handleKey(char key);
	void handleMouse(int x, int y, int status);

	void renderAll();
	void updateAll();
};

extern guiList GUIList;
#endif