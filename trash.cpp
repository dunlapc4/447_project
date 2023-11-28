#include "trash.h"


Trash::Trash(GLdouble theHeight, GLdouble theRad, float x, float y, float z) {
	//
}
//make overloaded constructors one default and one input
Trash::~Trash() {
	//
}

bool Trash::initialize() {
	//
	initialize = true;
	return true;
}

void Trash::draw() {
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);
	glCallList(displayList);
	glPopMatrix();
}