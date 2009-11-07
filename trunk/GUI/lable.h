#ifndef LABLE_H
#define LABLE_H

#include "basicElem.h"
#include <string.h>

class lable : public basicElem
{
private:
	std::string text;
	void render();
	void update();
public:
	void init(char* Text);//if constructor isnt possible
		lable(char* Text);// use init instead
		lable();

};

#endif