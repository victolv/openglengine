#include "font.h" 
#include "GL/glew.h"
#include <GL/gl.h>
#include <string.h>

font::~font()
{
	 glDeleteLists(base,256);
}
font::font()
{
}

void font::load(char* file)
{
	fileName = file;
fontIMG.load(file);


 glEnable(GL_TEXTURE_2D);
 glGenTextures(1,&fontIMG.ID);
 glBindTexture(GL_TEXTURE_2D,fontIMG.ID);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
 glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

 glTexImage2D(GL_TEXTURE_2D, 0, fontIMG.type, fontIMG.width, fontIMG.height, 0, fontIMG.type, 
		GL_UNSIGNED_BYTE, fontIMG.img);


    float cx;
    float cy;

    base = glGenLists(256);
    
    for(int i = 0; i < 256; i++)
    {
        cx = float(i%16)/16.0f;
        cy = float(i/16)/16.0f;

        glNewList(base+i,GL_COMPILE);
        glBegin(GL_QUADS);
            glTexCoord2f(cx,cy+0.0625f);
            glVertex2i(0,16);
            glTexCoord2f(cx+0.0625f,cy+0.0625f);
            glVertex2i(16,16);
            glTexCoord2f(cx+0.0625f,cy);
            glVertex2i(16,0);
            glTexCoord2f(cx,cy);
            glVertex2i(0,0);
        glEnd();
        glTranslated(10,0,0);
        glEndList();
    }
    glDisable(GL_TEXTURE_2D);

}
font::font(char* file)
{
fileName = file;
fontIMG.load(file);


 glEnable(GL_TEXTURE_2D);
 glGenTextures(1,&fontIMG.ID);
 glBindTexture(GL_TEXTURE_2D,fontIMG.ID);
 glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

 glTexImage2D(GL_TEXTURE_2D, 0, fontIMG.type, fontIMG.width, fontIMG.height, 0, fontIMG.type, 
		GL_UNSIGNED_BYTE, fontIMG.img);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    float cx;
    float cy;

    base = glGenLists(256);
    
    for(int i = 0; i < 256; i++)
    {
        cx = float(i%16)/16.0f;
        cy = float(i/16)/16.0f;

        glNewList(base+i,GL_COMPILE);
        glBegin(GL_QUADS);
            glTexCoord2f(cx,cy+0.0625f);
            glVertex2i(0,16);
            glTexCoord2f(cx+0.0625f,cy+0.0625f);
            glVertex2i(16,16);
            glTexCoord2f(cx+0.0625f,cy);
            glVertex2i(16,0);
            glTexCoord2f(cx,cy);
            glVertex2i(0,0);
        glEnd();
        glTranslated(10,0,0);
        glEndList();
    }
    glDisable(GL_TEXTURE_2D);
}
void font::render(float x, float y,const char *text)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,fontIMG.ID);
    glTranslatef(x,y,0);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glListBase(base);
    glCallLists(strlen(text),GL_UNSIGNED_BYTE,text);
    glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void font::render(float x, float y,const char *text, float size)
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,fontIMG.ID);
    glTranslatef(x,y,0);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glListBase(base);
	glScalef(size,size,1);
    glCallLists(strlen(text),GL_UNSIGNED_BYTE,text);
    glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
	font timesRoman;