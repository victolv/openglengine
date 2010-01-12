#ifndef CAMERA_H
#define CAMERA_h
#include <gl/gl.h>
#include "object.h"

class Camera : public object{
public:
object* followObject;
bool viewObject(object* view);
Camera();
void update();//once every update sesion, sets the camara to its pos
//void set(int[]..) not necasery
}extern camera;
#endif