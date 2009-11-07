#ifndef PARTICLES_H
#define PARTICLES_H
#include "particle.h"

class particles
{
public:
	particle* theParticles;
	int Ammount;
	float Direction[3];
	int Duration;
	float Size;
	float Speed;
	float xyz[3];
	float width;
	 float Color[3];
	 float Gravity;
	 void render();
	 void update();
	 particles(float size, int duration, float speed, int ammount, float* direction, float* color, float* posXYZ, float gravity);
	 particles();
	 void init(float size, int duration, float speed, int ammount, float* direction, float* color, float* posXYZ, float gravity);
	 ~particles();
};

#endif