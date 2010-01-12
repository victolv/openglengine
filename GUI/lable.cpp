#include "lable.h"
#include "text/font.h"

lable::lable(char* Text) : basicElem(0,0,50,50)
{
	text.assign(Text);
}
lable::lable() : basicElem(0,0,50,50)
{
}
void lable::init(char* Text)
{
	text.assign(Text);
}
void lable::render()
{
	timesRoman.render(posX + 5, posY + sizeY/2,text.c_str());
}
void lable::update(){}