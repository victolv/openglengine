#ifndef PLAYER_H
#define PLAYER_H
#include "../object.h"

class Player : public object/* : public collision : model?*/{
public://50 30 -10
	Player();
	float lastx,lasty;
	void updatePos(int x, int y, int z, int dir[3]);
}extern player;
#endif