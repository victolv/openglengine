#include "textbox.h"
#include <GL/gl.h>


const char* textbox::getString()
{
	return text.c_str();
}
void textbox::getString(char* theString)
{
	theString = const_cast<char*>(text.c_str());
}
int textbox::getInt()
{
	return atoi(text.c_str());
}
void textbox::getInt(int* theInt)
{
	theInt = new int;
	*theInt = atoi(text.c_str());
}
float textbox::getFloat()
{
	return 1;
}
void textbox::getFloat(float* theFloat)
{
}

textbox::textbox() : basicElem(0,0,150,25)
{
	//text = "hey,\n test test AB   CDefgGH";
	cursorPlace = text.length();
	recSelect = false;
	fontSize = 0.5;
}

void textbox::render()
{
	glColor4f(0.1,0.2,0.3,0.6);
	glBegin(GL_QUADS);
	glVertex2f(posX,posY);
	glVertex2f(posX + sizeX,posY);
	glVertex2f(posX + sizeX, posY + sizeY);
	glVertex2f(posX, posY + sizeY);
	glEnd();
	glColor3f(0,0,0.2);
	timesRoman.render(posX,posY + sizeY / 2 - 10, const_cast<char*>(text.c_str()));
	if(focus)
	{
	glColor4f(0.05,0.1,0.2,0.4);
	glBegin(GL_QUADS);
	glVertex2f(selectXBeg * 10 + posX,posY + sizeY / 2 - 8);
	glVertex2f(selectXBeg * 10 + posX,posY + sizeY / 2 + 8);
	glVertex2f(selectXEnd * 10 + posX,posY + sizeY / 2 + 8);
	glVertex2f(selectXEnd * 10 + posX,posY + sizeY / 2 - 8);
	glEnd();
	}
		if(focus == false)
		count = 0;

		glColor3f(0,0.3,0.9);
		if(focus && (count & 0x100))
		{
		glBegin(GL_LINES);
		glVertex2f(posX + cursorPlace*10 + 4,posY + sizeY / 2 - 10);
		glVertex2f(posX + cursorPlace*10 + 4,posY + sizeY / 2 + 10);
		glEnd();
		}
	//timesRoman.render(posX + cursorPlace*8 -2,posY + sizeY / 2 - 10,"|");

	

}

void textbox::update()
{
			count++;
			if(Mouse.pressedLMB())
			{
				cursorPlace = ((Mouse.getX() - posX)/(10));
				count = 0x100;
				
				if(recSelect == 0)
				{
					_select_lastClickedX = Mouse.pressedX();
					_select_lastClickedY = Mouse.pressedY();
					selectXBeg = (Mouse.getX() - posX)/(10);
					recSelect = true;
				}
				else if(recSelect == 1)
				//selectXEnd = (Mouse.getX() - posX) / 8;
				selectXEnd = cursorPlace;
			}
			if(!Mouse.pressedLMB() && !_select_lastClickedX != Mouse.pressedX())
			{
				recSelect = false;

			}
}

void textbox::handleKey(char key)
{
	switch(key)
	{
	case 8:
	case 127:
		if(selectXBeg < selectXEnd)
		{
			text.erase(text.begin()+selectXBeg, text.begin()+selectXEnd);
			cursorPlace -= selectXEnd - selectXBeg;
			selectXEnd = selectXBeg;
			recSelect = false;
			break;
		}
		else if(selectXBeg > selectXEnd)
		{
			text.erase(text.begin()+selectXEnd, text.begin()+selectXBeg);
			selectXBeg = selectXEnd;
			recSelect = false;
			break;
		}
		else if(key == 8)
		{
		if(cursorPlace > 0 && cursorPlace <= text.length())
		{
			text.erase(text.begin()+cursorPlace-1);
			cursorPlace--;
			break;
		}
		}
		else if(key == 127)
		if(cursorPlace >= 0 && cursorPlace < text.length())
		{
			text.erase(text.begin()+cursorPlace);
			break;	
		}
	case 20:
		if(cursorPlace > 0)
		cursorPlace--;
		break;
	case 19:
		if(cursorPlace < text.length())
		cursorPlace++;
		break;
	default:
		if(cursorPlace < text.length())
			text.insert(text.begin()+cursorPlace,key);
	text.push_back(key);
	cursorPlace++;
	}
	count = 0x100;
}
