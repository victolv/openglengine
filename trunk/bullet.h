#include "particle/particleEngine.h"

class bullet
{
private:
	friend class bulletlist;
	particles bulletParticle;
	float loc[3];
	float speed;
	float xrot;
	float yrot;
	float posscalc[3];
	int count;
	int place;
public:

	bullet *next;
	bullet(float posx, float posy, float posz, float xrot, float yrot, float speed);
	void render();
	void calcPossition();
	~bullet();
};

void addBullet(float xpos, float ypos, float zpos,float xrot, float yrot);
void renderBullet();
void updateBullet();

class bulletlist
{
private:
	//bullet *bulletStart;
public:
	bulletlist(int mode);
	void newBullet(float xpos, float ypos, float zpos,float xrot, float yrot);
	void updateAll();
	void renderAll();
};