#include "particle.h"

particle::particle(float* XYZ, float* Color)
{
	xyz[0] = XYZ[0]; xyz[1] = XYZ[1]; xyz[2] = XYZ[2];
	oldxyz[0] = XYZ[0]; oldxyz[1] = XYZ[1]; oldxyz[2] = XYZ[2];
	color[0] = Color[0]; color[1] = Color[1]; color[2] = Color[2];

}
void particle::configure(float* XYZ, float* Color)
{
	xyz[0] = XYZ[0]; xyz[1] = XYZ[1]; xyz[2] = XYZ[2];
	color[0] = Color[0]; color[1] = Color[1]; color[2] = Color[2];
	oldxyz[0] = XYZ[0]; oldxyz[1] = XYZ[1]; oldxyz[2] = XYZ[2];
}
particle::particle()
{
	age = 0;
}
void particle::reset()
{
	age = 0;
	xyz[0] = oldxyz[0]; xyz[1] = oldxyz[1]; xyz[2] = oldxyz[2];
	speed = orgSpeed;
}