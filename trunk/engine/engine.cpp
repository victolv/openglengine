#include "engine.h"

#include "gl/glut.h"

Engine engine;

gui MainMenu;

int noclip = true;

float temppos[3] = {0,0,20};//temp
//ook temp
particles particleTest(5,100,0.5,50000,temppos,temppos,temppos,1);

void mainMenu(){

	if(engine.logic){
		GUIList.add(&MainMenu);
		engine.dissableLogic();
	}
	else{
	GUIList.remove(&MainMenu);
	engine.enableLogic();
	}
}

void Engine::init(){
themeInit();
static gui MainMenu("Main Menu",blueWindow);
MainMenu.newElem(new button("exit",Exit));
GUIList.add(&MainMenu);

camera.viewObject(&player);
}
void Engine::update(){
particleTest.update();

GUIList.updateAll();

}

void Engine::dissableLogic(){
engine.logic = false;
}
void Engine::enableLogic(){
engine.logic = true;
}

void Engine::start(){

}
void Engine::render(){

glClearColor (0,0,0,1.0);
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
glColor4f(0.4, 0.3, 0.6, 0.55);

camera.update();

glPushMatrix();
renderBullet();
glPopMatrix();
glColor4f(1,0.3,0.3,1);
//								light test
float ambient[] = {0.20,0.20,0.20};
float diffuseLight[] = {0.20,0.20,0.60};
float place[] = {10,0,0};
glPushMatrix();
glRotatef(random.gen(0,360),0,1,0);
glTranslatef(100,30,0);
	glLightfv(GL_LIGHT0,GL_AMBIENT, ambient);
	glLightfv (GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv (GL_LIGHT0, GL_POSITION, place);
	glutSolidCube(5);
glPopMatrix();


static texture test("data//textures//test.bmp");
glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, test.ID);
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


particleTest.render();


GUIList.renderAll();
}

void Engine::handleMouse(int movedX, int movedY){
}
void handleKey(int ammount,char* keys, bool* status);
{//////////////////////////////////////////////////////////////////////////////////////////////working, this wont compile..
	case SDLK_ESCAPE:

		  mainMenu();

	break;

	  case SDLK_w:
		  {
			  std::cout << "ASD\n";
float xrotrad, yrotrad;
yrotrad = (player.directionY / 180 * 3.141592654f);
xrotrad = (player.directionX / 180 * 3.141592654f);
player.posX += float(sin(yrotrad)) * 5;//cscale
player.posY -= float(cos(yrotrad)) * 5;
if(noclip == true)
{
	player.posY -= float(sin(xrotrad)) * 5 ;
}
		  //camz -= 5;
break;
		  
	  case 's':
		  {
float xrotrad, yrotrad;
yrotrad = (player.directionY / 180 * 3.141592654f);
xrotrad = (player.directionX / 180 * 3.141592654f);
player.posX -= float(sin(yrotrad)) * 5;//cscale
player.posY += float(cos(yrotrad)) * 5;
if(noclip == true)
{
	player.posX += float(sin(xrotrad)) * 5;
}
		 // camz += 5;
break;
		  }
	  case 'd':
		  {
float yrotrad;
yrotrad = (player.directionY / 180 * 3.141592654f);
player.posX += float(cos(yrotrad)) * 5;
player.posZ += float(sin(yrotrad)) * 5;
		  //camx += 5;
		break;
		  }
	  case 'a':
		  {
float yrotrad;
yrotrad = (player.directionY / 180 * 3.141592654f);
player.posX -= float(cos(yrotrad)) * 5;
player.posZ -= float(sin(yrotrad)) * 5;
		 // camx -= 5;
break;
		  }
	  case '8':
		  player.directionX -= 1;
		if (player.directionX < -360) player.directionX += 360;
		  break;
	  case '2':
		  player.directionX += 1;
		if (player.directionX >360) player.directionX -= 360;
		  break;
	  case ' ':
		  player.posY += 5;
		  break;
	  case '5':
		  player.posY -= 5;
		  break;
	  case 'e':
		  addBullet(player.posX, player.posY, player.posZ, player.directionX, player.directionY);
		  break;
	  case 'n':
		  if(noclip == false) noclip = true;
		  else noclip = false;
		  break;
	  /*case 'f':
		  if(fpsOn == true) fpsOn = false;
		  else fpsOn = true;
		  break;
		  */
		  }
	  }
		  if(/*guiFocus&&*/(event.key.keysym.unicode & 0x7F) == event.key.keysym.unicode && isascii(event.key.keysym.unicode))
		  {
			  if(event.key.keysym.unicode)
			 GUIList.handleKey(event.key.keysym.unicode);
			  else
				  GUIList.handleKey(event.key.keysym.sym);
		  }
		 }
	 }

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
			  std::cout << "ASD\n";
float xrotrad, yrotrad;
yrotrad = (player.directionY / 180 * 3.141592654f);
xrotrad = (player.directionX / 180 * 3.141592654f);
player.posX += float(sin(yrotrad)) * 5;//cscale
player.posY -= float(cos(yrotrad)) * 5;
if(noclip == true)
{
	player.posY -= float(sin(xrotrad)) * 5 ;
}
		  //camz -= 5;
break;
		  
	  case 's':
		  {
float xrotrad, yrotrad;
yrotrad = (player.directionY / 180 * 3.141592654f);
xrotrad = (player.directionX / 180 * 3.141592654f);
player.posX -= float(sin(yrotrad)) * 5;//cscale
player.posY += float(cos(yrotrad)) * 5;
if(noclip == true)
{
	player.posX += float(sin(xrotrad)) * 5;
}
		 // camz += 5;
break;
		  }
	  case 'd':
		  {
float yrotrad;
yrotrad = (player.directionY / 180 * 3.141592654f);
player.posX += float(cos(yrotrad)) * 5;
player.posZ += float(sin(yrotrad)) * 5;
		  //camx += 5;
		break;
		  }
	  case 'a':
		  {
float yrotrad;
yrotrad = (player.directionY / 180 * 3.141592654f);
player.posX -= float(cos(yrotrad)) * 5;
player.posZ -= float(sin(yrotrad)) * 5;
		 // camx -= 5;
break;
		  }
	  case '8':
		  player.directionX -= 1;
		if (player.directionX < -360) player.directionX += 360;
		  break;
	  case '2':
		  player.directionX += 1;
		if (player.directionX >360) player.directionX -= 360;
		  break;
	  case ' ':
		  player.posY += 5;
		  break;
	  case '5':
		  player.posY -= 5;
		  break;
	  case 'e':
		  addBullet(player.posX, player.posY, player.posZ, player.directionX, player.directionY);
		  break;
	  case 'n':
		  if(noclip == false) noclip = true;
		  else noclip = false;
		  break;
	  /*case 'f':
		  if(fpsOn == true) fpsOn = false;
		  else fpsOn = true;
		  break;
		  */
		  }
	  }
		  if(/*guiFocus&&*/(event.key.keysym.unicode & 0x7F) == event.key.keysym.unicode && isascii(event.key.keysym.unicode))
		  {
			  if(event.key.keysym.unicode)
			 GUIList.handleKey(event.key.keysym.unicode);
			  else
				  GUIList.handleKey(event.key.keysym.sym);
		  }
		 }
	 }
}