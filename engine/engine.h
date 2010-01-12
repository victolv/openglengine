#ifndef ENGINE_H
#define ENGINE_H
#include <gl/gl.h>
#include <SDL/SDL.h>
#include <math.h>

//#include "../gmScript/scripting.h"
#include "../image/img.h"
#include "../screen/resize.h"
#include "../bullet.h"
#include "../GUI/simpleGUI.h"
#include "../mouse/mouse.h"
#include "../screen/resize.h"
#include "../testfunctions.h"
#include "../random.h"
#include "../particle/particleEngine.h"

#include "player/player.h"
#include "camera.h"
//#include "../tasks/dyeCalc/dye.h"

extern particles particleTest;

void events();

class Engine{
private:
bool logic;
public:
bool noclip;

friend void mainMenu();

void handleMouse(int movedX, int movedY);
void init();
void start();
void update();
void render();
void dissableLogic();
void enableLogic();
}extern engine;
#endif