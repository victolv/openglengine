#ifndef PARTICLE_H
#define PARTICLE_H
class particle
{
public:
	float oldxyz[3];
	float xyz[3];
	float color[4];
	int age;
	float speed;
	float orgSpeed;
	particle(float* XYZ, float* Color);
	particle();
	void configure(float* XYZ, float* Color);
	void reset();
};

#endif