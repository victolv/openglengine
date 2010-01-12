#include "particles.h"
#include <GL/glew.h>
#include <GL/glext.h>
#include <GL/gl.h>

#include "../random.h"
#include "../image/texture.h"

texture* vuur;

particles::particles()
 {
 }
void particles::init(float size, int duration, float speed, int ammount, float* direction, float* color, float* posXYZ, float gravity)
 {
	 Color[0] = color[0];Color[1] = color[1]; Color[2] = color[2];
	Gravity = gravity;
	vuur = new texture("data/textures/vuur.jpg");
	///////

Direction[0] = direction[0]; Direction[1] = direction[1]; Direction[2] = direction[2];
float tempPos[3] = {posXYZ[0],posXYZ[1],posXYZ[2]};
float tempColor[4] = {0.76,0,0.4,0.8};
theParticles = new particle[ammount];
for(int i = 0;i < ammount;i++)
{
	theParticles[i].configure(tempPos,tempColor);
	theParticles[i].speed = random.gen(speed / 2, speed * 2);
	theParticles[i].orgSpeed = theParticles[i].speed;
}
Size = size;
Duration = duration;
Speed = speed;
Ammount = ammount;
Direction[0] = direction[0]; Direction[1] = direction[1]; Direction[2] = direction[2];

 }


particles::~particles()
{
	delete[] theParticles;
}

particles::particles(float size, int duration, float speed, int ammount, float* direction, float* color, float* posXYZ, float gravity)
 {
	 Color[0] = color[0];Color[1] = color[1]; Color[2] = color[2];
	Gravity = gravity;
	vuur = new texture("data/textures/vuur.jpg");
	///////

Direction[0] = direction[0]; Direction[1] = direction[1]; Direction[2] = direction[2];
float tempPos[3] = {posXYZ[0],posXYZ[1],posXYZ[2]};
float tempColor[4] = {0.76,0,0.4,0.8};
theParticles = new particle[ammount];
for(int i = 0;i < ammount;i++)
{
	theParticles[i].configure(tempPos,tempColor);
	theParticles[i].speed = random.gen(speed / 2, speed * 2);
	theParticles[i].orgSpeed = theParticles[i].speed;
}
Size = size;
Duration = duration;
Speed = speed;
Ammount = ammount;
Direction[0] = direction[0]; Direction[1] = direction[1]; Direction[2] = direction[2];

}
float quadratic[] =  { 1.0f, 0.0f, 0.01f,0,0 };

void particles::render()
{


glBindTexture(GL_TEXTURE_2D, vuur->ID);
//glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, quadratic);
glEnable(GL_POINT_SPRITE);
glEnable(GL_TEXTURE_2D);
glTexEnvi(GL_POINT_SPRITE, GL_COORD_REPLACE, GL_TRUE);

glPushAttrib(GL_COLOR_BUFFER_BIT);
glColor4f(0,0,0,0.1);
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE);
glPointSize(16);
	glColor3fv(theParticles->color);
	glBegin(GL_POINTS);
	for(int i = 0;i < Ammount;i++)
	{
		glVertex3fv(theParticles[i].xyz);
	}
	glEnd();
glPointSize(1);
glPopAttrib();
glDisable(GL_POINT_SPRITE);
glDisable(GL_TEXTURE_2D);
}

void particles::update()
{

	for(int i = 0; i < Ammount;i++)
	{
		if(theParticles[i].age > Duration)
		theParticles[i].reset();
		else
		theParticles[i].xyz[0] += random.gen(-2,2);
		theParticles[i].xyz[1] += theParticles[i].speed;
		theParticles[i].xyz[2] += random.gen(-2,2);
		theParticles[i].age++;
		theParticles[i].speed -= Gravity / 100;

	}
}