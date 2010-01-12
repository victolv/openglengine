#include "camera.h"
Camera camera;

Camera::Camera(){
followObject = 0;
}
bool Camera::viewObject(object* view){
	followObject = view;
	return true;
}

void Camera::update()//
{
	if(followObject != 0){
		glRotatef(followObject->viewX,1.0,0.0,0.0);
		glRotatef(followObject->viewY,0.0,1.0,0.0);
		glTranslated(-followObject->posX,-followObject->posY,-followObject->posZ);
	}
	else{
		glRotatef(viewX,1.0,0.0,0.0);
		glRotatef(viewY,0.0,1.0,0.0);
		glTranslated(-viewX,-viewY,-viewZ);
	}
}
