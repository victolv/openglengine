#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <gl/glext.h>
#include <math.h>
#include <windows.h>

#include "gmScript/scripting.h"
#include "image/img.h"
#include "screen/resize.h"
#include "bullet.h"
#include "GUI/simpleGUI.h"
#include "mouse/mouse.h"
#include "screen/resize.h"
#include "testFunctions.h"
#include "random.h"
#include "particle/particleEngine.h"

#include "tasks/dyeCalc/dye.h"


#pragma comment(lib,"SDL.lib")
#pragma comment(lib,"SDLmain.lib")

using namespace std;

unsigned buttontex;


SDL_Surface* screen;

float bigColorArray[10000];
int testArray[100];



particles* particleTest;


//		--------------
gui *MainMenu;
gui *MainMenu1;
gui* texwin;
gui* dyeWin;

textbox* texttest;
textbox* console;

slidebar *dye1, *dye2, *dye3;
//		_______________

texture* windowTEX[8];
texture* test;



bool noclip = false;

//simpleGUI * MainMenu(


int count = 0;
float spin = 0;

bool wincol1, wincol2;

float camx = 50,camy = 30,camz = -10;
float xrot = 0, yrot = 0;


float lastx,lasty;

float bounce;
float cScale = 5.0;

bool guiRender = false;		//temp..
bool guiFocus = false;

int fpsCount = 0;
bool fpsOn = false;

bool chckbox = false;
float particleAmmount;


GLfloat DiffuseLight[] = {1.0, 0.5, 0.5};
	GLfloat ambient[] = {0.1,0.1,0.1};
GLfloat LightPosition[] = {0, 0, 0, 1};

float wincount = 0;

float c1,c2,c3;


const char* testTextA;
void printText()
{
	std::cout << testTextA << std::endl;
}

void mainMenu()
{
	if(guiRender)
	{
	guiRender = false;
	guiFocus = false;
	}
	else
	{
	guiRender = true;
	guiFocus = true;
	}

}

void timer(int msecs, void(*func)())
{

	static long lastTime;// = 0;
	static long nowTime;// = GetTickCount();

	if(lastTime >= nowTime + msecs)
	{
		func();
		lastTime = nowTime;
		nowTime = GetTickCount();
	}

	else
	{
		lastTime = GetTickCount();
		return;
	}
			if(fpsOn)
		{
			fpsCount = (nowTime - lastTime) * 60;
			cout << fpsCount << endl;
			fpsOn = false;
		}

	}



//glutWarpPointer(windowWidth / 2, windowHeight / 2);


void camera()
{

glRotatef(xrot,1.0,0.0,0.0);
glRotatef(yrot,0.0,1.0,0.0);
glTranslated(-camx,-camy,-camz);
}

void gaNaarWowomg()
{
	system("start iexplore http://www.wowomg.com/rofl");
}

void init(void)
{
	//		engine Init's
	//		_____________
	timesRoman.load("data/font.png");
	random.gen(0.5,0.95,10000,bigColorArray);
	for(int i = 0;i < 5000;i++)
		std::cout << bigColorArray[i] << std::endl;
	random.gen(2,9,1000,testArray);
	glEnable(GL_TEXTURE_2D);
	themeInit();

	float temppos[3] = {0,0,20};
	
	particleTest = new particles(5,100,0.5,50000,temppos,temppos,temppos,1);


	windowTEX[0] = new texture("data/GUI/window1.bmp");
	windowTEX[1] = new texture("data/GUI/window2.jpg");
	windowTEX[2] = new texture("data/GUI/window3.jpg");
	windowTEX[3] = new texture("data/GUI/window4.jpg");
	windowTEX[4] = new texture("data/GUI/window5.jpg");
	windowTEX[5] = new texture("data/GUI/window6.jpg");
	windowTEX[6] = new texture("data/GUI/window7.jpg");
	windowTEX[7] = new texture("data/GUI/window8.jpg");

	test = new texture("data/textures/test.bmp");

	dye1 = new slidebar(0,255);
	dye2 = new slidebar(0,255);
	dye3 = new slidebar(0,255);
	
	dyeWin = new gui;

	dyeWin->newElem(dye1);
	dyeWin->newElem(dye2);
	dyeWin->newElem(dye3);
	dyeWin->newElem(new button("Calculate",dyeCalcWrapper));



	 MainMenu = new gui("Main Menu...   lol",blueWindow);
	 MainMenu1 = new gui("TEST...   lol",greenWindow);
	texttest = new textbox;
	console = new textbox;
	 int as = 0;
	// MainMenu->newElem(console);
	//MainMenu->newElem(new button(exec,
	MainMenu->newElem(new button("Quit", Exit));
	MainMenu->newElem(new checkbox(wincol1));
	MainMenu->newElem(new slidebar(50,0.2,1, blueWindow->window.topColor[2]));
	MainMenu->newElem(new colorPicker(&as));
	MainMenu->newElem(new slidebar(0,50000,particleAmmount));
	MainMenu->newElem(texttest);
	MainMenu1->newElem(new checkbox(wincol2));
	MainMenu1->newElem(new slidebar(0,1, c1));
	MainMenu1->newElem(new slidebar(0,1,c2));
	MainMenu1->newElem(new slidebar(0,1,c3));
	MainMenu1->newElem(new slidebar(50,0.2,1, greenWindow->window.topColor[1]));
	MainMenu1->newElem(new slidebar(120,0,7,wincount));
	MainMenu1->newElem(new button("text test",printText));
	MainMenu->newElem(new lable("Hi!"));
	//////////////////////////////

	gmScriptInit();
	///////////////////////////
	glMatrixMode(GL_MODELVIEW);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	//texwin = new gui(0,0,200,400,"as",textureWindow);
   glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
   glDepthFunc(GL_LEQUAL);
   glShadeModel(GL_SMOOTH);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
	glLightfv (GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
	glLightfv (GL_LIGHT0, GL_POSITION, LightPosition);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
	int buf, sbuf;
	glGetIntegerv(GL_SAMPLE_BUFFERS_ARB, &buf);
	glGetIntegerv(GL_SAMPLES_ARB,&sbuf);
	cout << "GL_SAMPLE_BUFFERS_ARB = " << buf << endl;
	cout << "GL_SAMPLES_ARB = " << sbuf << endl;
	glEnable(GL_BLEND);


	GUIList.add(MainMenu);
	GUIList.add(MainMenu1);
	//GUIList.add(texwin);
	GUIList.add(dyeWin);
}

void update()
{
	particleTest->update();

	if(guiFocus && guiRender)
	{
	GUIList.updateAll();

	particleTest->Ammount = (int)particleAmmount;
	if(!wincol1 == true)		MainMenu->options = blueWindow;
	else					MainMenu->options = greenWindow;

	if(wincol2 == true)		MainMenu1->options = blueWindow;
	else					MainMenu1->options = greenWindow;

	textureWindow->window.windowText = windowTEX[(int)wincount];

	testTextA = texttest->getString();

	dyeCalc.update((int)dye1->getValue(),(int)dye2->getValue(),(int)dye3->getValue());
	
	}

	updateBullet();
	spin += 0.2;

	if(!guiFocus)
	{
		yrot += (float) (Mouse.getdiffX() % 360);
		xrot += (float) (Mouse.getdiffY() % 360);
	}
}

void display()
{
glClearColor (c1,c2,c3,1.0);
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glColor4f(0.4, 0.3, 0.6, 0.55);



camera();
glPushMatrix();
renderBullet();
glPopMatrix();
glColor4f(1,0.3,0.3,1);
//								light test
glPushMatrix();
glRotatef(spin,0,1,0);
glTranslatef(100,30,0);
	glLightfv(GL_LIGHT0,GL_AMBIENT, ambient);
	glLightfv (GL_LIGHT0, GL_DIFFUSE, DiffuseLight);
	glLightfv (GL_LIGHT0, GL_POSITION, LightPosition);
	glutWireCube(20);
glPopMatrix();


glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, test->ID);
glBegin(GL_QUADS);
glTexCoord2i(0,0);glVertex3f(10,10,20);
glTexCoord2i(1,0);glVertex3f(20,10,20);
glTexCoord2i(1,1);glVertex3f(20,20,20);
glTexCoord2i(0,1);glVertex3f(10,20,20);
glEnd();
glDisable(GL_TEXTURE_2D);

//								light test
glutSolidSphere(20,24,48);
glColor4f(0,0,0.4,0.95);

//glRotatef(-xrot,1,0,0);
//glRotatef(-yrot,0,1,0);
//glTranslatef(-camx,-camy,-camz);

glBegin(GL_QUADS);
glVertex3f(10, -30, 40);
glVertex3f(40, -30,  40);
glVertex3f( 40, 30,  40);
glVertex3f(  1, 30,  40);
glEnd();


	particleTest->render();

if(guiRender)
{
GUIList.renderAll();
}
}

/*
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(60.0, (GLfloat)w/(GLfloat)h,0,2000);
   glMatrixMode (GL_MODELVIEW);
   glLoadIdentity ();
   windowWidth = w;
   windowHeight = h;
}*/

void events(/*unsigned char key, int x, int y*/)
{
	SDL_Event event;

while (SDL_PollEvent(&event))   //Poll our SDL key event for any keystrokes.
{
  switch(event.type)
  {
	   case SDL_VIDEORESIZE:
        
        reshape(event.resize.w,event.resize.h);
		//screen = SDL_SetVideoMode(getWindowWidth(), getWindowHeight(), 32, SDL_OPENGL | SDL_DOUBLEBUF | SDL_RESIZABLE);
        break;
        
      case SDL_QUIT:
        mainMenu();
        break;  



	  case SDL_MOUSEMOTION :
		  Mouse.setXY(event.motion.x, event.motion.y);
		if(guiFocus)
			 GUIList.handleMouse(event.button.x, event.button.y,event.type);
		  break;

	  case SDL_MOUSEBUTTONDOWN:
	  case SDL_MOUSEBUTTONUP: 

		 Mouse.clickHandle(event.button.button , event.type,event.button.x, event.button.y);
		break;
  
	  case SDL_KEYDOWN:
      switch(event.key.keysym.sym){


	case SDLK_ESCAPE:

		  mainMenu();

	break;

	  case SDLK_w:
		  {
			  cout << "ASD\n";
float xrotrad, yrotrad;
yrotrad = (yrot / 180 * 3.141592654f);
xrotrad = (xrot / 180 * 3.141592654f);
camx += float(sin(yrotrad)) * cScale;
camz -= float(cos(yrotrad)) * cScale;
if(noclip == true)
{
camy -= float(sin(xrotrad)) * cScale ;
}
bounce += 0.04;
		  //camz -= 5;
break;
		  
	  case 's':
		  {
float xrotrad, yrotrad;
yrotrad = (yrot / 180 * 3.141592654f);
xrotrad = (xrot / 180 * 3.141592654f);
camx -= float(sin(yrotrad)) * cScale;
camz += float(cos(yrotrad)) * cScale;
if(noclip == true)
{
camy += float(sin(xrotrad)) * cScale;;
}
bounce += 0.04;
		 // camz += 5;
break;
		  }
	  case 'd':
		  {
float yrotrad;
yrotrad = (yrot / 180 * 3.141592654f);
camx += float(cos(yrotrad)) * cScale;
camz += float(sin(yrotrad)) * cScale;
		  //camx += 5;
		break;
		  }
	  case 'a':
		  {
float yrotrad;
yrotrad = (yrot / 180 * 3.141592654f);
camx -= float(cos(yrotrad)) * cScale;
camz -= float(sin(yrotrad)) * cScale;
		 // camx -= 5;
break;
		  }
	  case '8':
		xrot -= 1;
		if (xrot < -360) xrot += 360;
		  break;
	  case '2':
		  xrot += 1;
		if (xrot >360) xrot -= 360;
		  break;
	  case ' ':
		  camy += 5;
		  break;
	  case '5':
		  camy -= 5;
		  break;
	  case 'e':
		  addBullet(camx, camy, camz, xrot, yrot);
		  break;
	  case 'n':
		  if(noclip == false) noclip = true;
		  else noclip = false;
		  break;
	  case 'f':
		  if(fpsOn == true) fpsOn = false;
		  else fpsOn = true;
		  break;
		  }
	  }
		  if(guiFocus && (event.key.keysym.unicode & 0x7F) == event.key.keysym.unicode && isascii(event.key.keysym.unicode))
		  {
			  if(event.key.keysym.unicode)
			 GUIList.handleKey(event.key.keysym.unicode);
			  else
				  GUIList.handleKey(event.key.keysym.sym);
		  }
		 }
	}
}

int main(int argc, char **argv)
{
if(	SDL_Init( SDL_INIT_NOPARACHUTE | SDL_INIT_VIDEO))
{
	cout << "noo\n";
}


SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

reshape(800,600);
	SDL_WM_SetCaption("SDL Test", "SDL Test");
	screen = SDL_SetVideoMode(800, 600, 32, SDL_OPENGL | SDL_DOUBLEBUF | SDL_RESIZABLE);
			   init();	
	//RESIZE EVENT-!!-----------/
		SDL_Event resizeEvent;
		resizeEvent.type=SDL_VIDEORESIZE;
		resizeEvent.resize.w=getWindowWidth();
		resizeEvent.resize.h=getWindowHeight();
		SDL_PushEvent(&resizeEvent);
		SDL_EnableUNICODE(1);
		//--------------------/
	initTest();
	

	if(screen == 0)
		cout << "ERROR";

	//////////////////////////////// THE LOOP!!!
	for(;;)
	{
		timer(10, update);
		events();
		display();
		SDL_GL_SwapBuffers();
	}
   return 0;
}
