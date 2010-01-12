#include "image.h"

image::image()
{

}
image::image(char* file)
{

	ilInit();
	 ilGenImages(1, &ID); /* Generation of one image name */
	 ilBindImage(ID); /* Binding of image name */
	if(!ilLoadImage(file))
	{
		img = new unsigned char[2];
		return;
	}
	width = ilGetInteger(IL_IMAGE_WIDTH);
	height = ilGetInteger(IL_IMAGE_HEIGHT);
	type = ilGetInteger(IL_IMAGE_FORMAT);

	if(type == IL_RGB)
		size = 3;
	else
	size = 4;

	img = new unsigned char[width * height * size];
	ilCopyPixels(0, 0, 0, width, height,
    1, type, IL_UNSIGNED_BYTE, img);

	ilDeleteImages(1, &ID);
	ID = 0;
}
void image::loadFile(char* file)
{

	ilInit();
	 ilGenImages(1, &ID); /* Generation of one image name */
	 ilBindImage(ID); /* Binding of image name */
	if(!ilLoadImage(file))
	{
		img = new unsigned char[2];
		this->~image();
		return;
	}
	width = ilGetInteger(IL_IMAGE_WIDTH);
	height = ilGetInteger(IL_IMAGE_HEIGHT);
	type = ilGetInteger(IL_IMAGE_FORMAT);

	if(type == IL_RGB)
		size = 3;
	else
	size = 4;

	img = new unsigned char[width * height * size];
	ilCopyPixels(0, 0, 0, width, height,
    1, type, IL_UNSIGNED_BYTE, img);

	ilDeleteImages(1, &ID);
	ID = 0;
}

image::~image()
{
	delete[] img;
}