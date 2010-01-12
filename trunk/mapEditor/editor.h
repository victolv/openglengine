#ifndef EDITOR_H
#define EDITOR_H
#include "../engine/engine.h"
class MapEditor{
	char* data;
	void start();
	void stop();
	bool loadFile(char* file);
	bool saveFile(char* file);
}extern mapEditor;
#endif