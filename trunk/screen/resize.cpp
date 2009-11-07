#include <gl/gl.h>
#include <gl/glut.h>
#include "resize.h"
int width = 800;
int height = 600;

int getWindowHeight()
{
return height;
}

int getWindowWidth()
{
return width;
}



void reshape (int w, int h)
{
   width = w;
   height = h;

   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (GLfloat)w/(GLfloat)h,1,20000);
   glMatrixMode (GL_MODELVIEW);
   glLoadIdentity ();
}