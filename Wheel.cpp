#include "Wheel.h"


Wheel::Wheel(float x, float y, float z) {
	displayList = 0;
	initialized = false;
	coord[0] = x;
	coord[1] = y;
	coord[2] = z;
	base = 2.0;
}

Wheel::~Wheel() {
	if (initialized) {
		glDeleteLists(displayList, 1);
		gluDeleteQuadric(qobj);
	}
}

bool Wheel::initialize() {

	qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);

	displayList = glGenLists(1);
	glNewList(displayList, GL_COMPILE);

	glColor3f(0.0, 0.0, 1.0);

	gluCylinder(qobj, 5, 5, 2, 9, 9);
	glTranslatef(0.0, 0.0, 2);
	gluDisk(qobj, 0, 5, 9, 9);

	glTranslatef(0.0, 4.5f, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	gluCylinder(qobj, 0.5, 0.5, 5, 5, 9);

	glTranslatef(0.0, -9.0, 0);
	gluCylinder(qobj, 0.5, 0.5, 5, 5, 9);

	glTranslatef(0.0, 4.5f, 0.0);
	glTranslatef(4.5, 0.0, 0.0);
	gluCylinder(qobj, 0.5, 0.5, 5, 5, 9);

	glTranslatef(-9.0, 0.0, 0.0);
	gluCylinder(qobj, 0.5, 0.5, 5, 5, 9);

	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(4.5f, 0.0, 5);
	gluDisk(qobj, 0.0, 5, 9, 9);
	//	glTranslatef(4.5, 0.0, 5);
		//gluCylinder(qobj, 5, 5, 2, 9, 9);

	glEndList();

	



	initialized = true;
	return true;
}

void Wheel::draw() { //its rotating but its rotating the trees and walls and not just the wheel
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);
	glRotatef(base, 0, 0, 1);
	glCallList(displayList);
	glPopMatrix();
}


void Wheel::update(float updateVal) {
	base += updateVal * 10;
	top += updateVal * 2.0f;
}



