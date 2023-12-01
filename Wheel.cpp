#include "Wheel.h"


Wheel::Wheel(){
	  displayList = 0;
	  initialized = false; 
	  coord[0] = coord[1] = coord[2]; 
}

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
//i want to make a wheel with cylinders on the sides and bars in the center so its easier to see it moving
	glRotatef(90, 1, 0, 0);
	//glTranslatef(4.5, 0.0, 0.0); 
	glColor3f(0.0, 0.0, 1.0);

	gluCylinder(qobj, 5, 5, 2, 9, 9); //make the cylinder for side
	glTranslatef(0.0, 0.0, 2);
	gluDisk(qobj, 0, 5, 9, 9);//make the first disk

	glTranslatef(0.0, 4.5f, 0.0); //make the bars for this i will keep it at 4 to keep it simple
	glColor3f(0.0, 0.0, 0.0);
	gluCylinder(qobj, 0.5, 0.5, 5, 5, 9);

	glTranslatef(0.0, -9.0, 0);
	gluCylinder(qobj, 0.5, 0.5, 5, 5, 9);

	glTranslatef(0.0, 4.5f, 0.0);
	glTranslatef(4.5, 0.0, 0.0);
	gluCylinder(qobj, 0.5, 0.5, 5, 5, 9);

	glTranslatef(-9.0, 0.0, 0.0);
	gluCylinder(qobj, 0.5, 0.5, 5, 5, 9);

	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(4.5f, 0.0, 4.5); //make the disk on the other end
	gluDisk(qobj, 0.0, 5, 9, 9);
	//going to cover the original side up with some type of cube or support structure. Planning to try to do subdivision on that one 

	glEndList();

	



	initialized = true;
	return true;
}

void Wheel::draw() { //its rotating but its rotating the trees and walls and not just the wheel
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);
	glRotatef(base, 0, 1, 0);
	glCallList(displayList);
	glPopMatrix();
}


void Wheel::update(float updateVal) {
	base += updateVal * 10;
}



