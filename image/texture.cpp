#include <GL/gl.h>
#include <GL/glu.h>

#include "texture.h"

texture::texture()
{
}
texture::texture(char* file) : image(file)
{
	glEnable(GL_TEXTURE_2D);
glGenTextures(1, &ID);


glBindTexture(GL_TEXTURE_2D, ID);
glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR );

gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, type, GL_UNSIGNED_BYTE, img);


	//delete[] img;
glDisable(GL_TEXTURE_2D);
}
void texture::load(char* file)
{
	loadFile(file);
	glEnable(GL_TEXTURE_2D);
glGenTextures(1, &ID);


glBindTexture(GL_TEXTURE_2D, ID);
glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );
glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR );

gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, type, GL_UNSIGNED_BYTE, img);


//delete[] img;
glDisable(GL_TEXTURE_2D);
}

texture::~texture()
{
	glDeleteTextures(1, &ID);
}