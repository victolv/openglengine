#ifndef IMAGE_H
#define IMAGE_H
#include <IL/IL.h>

#pragma comment(lib, "DevIL.lib")

class image
{
private:
public:
image();
image(char* file);
void loadFile(char* file);
~image();
unsigned char* img;
unsigned int ID;
int type;
int size;
int width;
int height;

};
#endif