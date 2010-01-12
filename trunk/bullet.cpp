#include <iostream>
#include <gl/gl.h>
#include <gl/glut.h>
#include "bullet.h"
#include <math.h>


using namespace std;

 // ---------------------//
				// bullet storage class.
// ---------------------/

int bulletAmmount = 0;
int bulletFreePlace = 0;		// still in test
//	bullet **pBullet = new *bullet[maxBullets];
bullet *pBullet = 0;
bullet *bulletStart;

bullet *activeBullet = 0;
bulletlist bulletListA(0);


void bullet::calcPossition()
{
	loc[0] += posscalc[0];
	loc[1] -= posscalc[1];
	loc[2] -= posscalc[2];
	count++;
	bulletParticle.update();
}

void bullet::render()
{
	//	calcPossition();

	glPushMatrix();
	glColor3f(1,0,0);
	{
		//glPushMatrix();
		//	glTranslatef(loc[0],loc[1],loc[2]);
			//glutSolidCube(10);
			glTranslatef(loc[0],loc[1], loc[2]);
			glutSolidCube(5);
			bulletParticle.render();


	//	glPopMatrix();
	}
	glPopMatrix();

	if(count > 2000)		delete this;
}

bullet::bullet(float posx, float posy, float posz, float xrotate, float yrotate, float paramspeed = 0.2)
{

	float colorTemp[3] = {0,0,0};
	bulletParticle.init(0,50,0.5,50,posscalc,colorTemp,loc,5);
	//	place = bulletFreePlace;

	loc[0]= posx;
	loc[1] = posy;
	loc[2] = posz;

	xrot = xrotate;
	yrot = yrotate;
	speed = paramspeed;
	count = 0;
	next = 0;

	float xrotrad, yrotrad;
	yrotrad = (yrot / 180 * 3.141592654f);
	xrotrad = (xrot / 180 * 3.141592654f);
	posscalc[0] = float(sin(yrotrad)) * speed;
	posscalc[1] = float(sin(xrotrad)) * speed;
	posscalc[2] = float(cos(yrotrad)) * speed;

	//activeBullet = this;
}

bullet::~bullet()
	{
		//bulletFreePlace = place;
		bulletStart = next;
	}


bulletlist::bulletlist(int mode)
{
	bulletStart = 0;
	cout << "asd\n";
}
void bulletlist::renderAll()
{
	if(bulletStart)
	{

		glDisable(GL_LIGHTING);

		bullet *temp2;
		for(bullet *temp = bulletStart; temp != NULL;temp = temp2)
		{
			temp2 = temp->next;
			temp->render();
		}
		glEnable(GL_LIGHTING);
	}
}


void bulletlist::updateAll()
{


	if(bulletStart)
		{
			for(bullet *temp = bulletStart; temp != NULL;temp = temp->next)
			{
				temp->calcPossition();
			}
		}
	//else(bulletStart =
}

void bulletlist::newBullet(float xpos, float ypos, float zpos,float xrot, float yrot)
{
	if(!bulletStart)
	{
		bulletStart = new bullet(xpos, ypos, zpos, xrot, yrot, 0.5);
		activeBullet = bulletStart;
	}
	else
	{
		activeBullet->next = new bullet(xpos, ypos, zpos, xrot, yrot, 0.5);
		activeBullet = activeBullet->next;
	}

		//	for(activeBullet;!activeBullet->next;activebullet = temp.next)

}


void addBullet(float posx, float posy, float posz, float xrot, float yrot)
{
	bulletListA.newBullet(posx, posy, posz, xrot, yrot);
}

void renderBullet()
{
	bulletListA.renderAll();
}


void updateBullet()
{


	bulletListA.updateAll();


}
