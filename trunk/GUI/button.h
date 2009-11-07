#ifndef BUTTON_H
#define BUTTON_H
#include "basicElem.h"


class button : public basicElem
{
private:
bool release;
char* text;
void ourColor();
void (*onLMBClick)();
bool clickOnce;
protected:
public:
void render();
void update();
button(float x, float y,float width, float height,char* Text, void (*onClick)());
button(float width, float height, char* Text, void (*onClick)());
button(char* Text, void (*onClick)());
};
#endif