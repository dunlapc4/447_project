#include "Wheel.h"


Wheel::Wheel(float x, float y, float z) {
	displayList[0] = 0;
	displayList[1] = 0;
	initialized = false;
	coord[0] = x;
	coord[1] = y;
	coord[2] = z;
}

Wheel::~Wheel() {
	if (initialized) {
		glDeleteLists(displayList[0], 1);
		glDeleteLists(displayList[1], 1);
		gluDeleteQuadric(qobj);
	}
}

bool Wheel::initialize() {
	
	qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);

	displayList[0] = glGenLists(1);
	glNewList(displayList[0], GL_COMPILE);

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

	/*displayList[1] = glGenLists(1);
	glNewList(displayList[1], GL_COMPILE);
	glColor3f(1.0, 0.0, 0.0);
	glRotated(90, 1, 0, 0);
	glEndList();*/

	initialized = true;
	return true;
}

void Wheel::draw() {
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);
	glCallList(displayList[0]);
	glPopMatrix();
}


void Wheel::update(float updateVal) {
	base += updateVal;
	top += updateVal * 2.0f;
}