#include "trash.h"


Trash::Trash(GLdouble theHeight, GLdouble theRad, float x, float y, float z) {
	initialized = false;
	displayList = 0;
	height = theHeight;
	rad = theRad;
	coord[0] = x;
	coord[1] = y;
	coord[2] = z;
}
//make overloaded constructors one default and one input
Trash::~Trash() {
	if (initialized) {
		glDeleteLists(displayList, 1);
		gluDeleteQuadric(qobj);
	}
}

bool Trash::initialize() {
	//this is going to initialize the object by building it from scratch and not using the glCylindar command 
	qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);
	displayList = glGenLists(1);
	glNewList(displayList, GL_COMPILE);
	//make the bin part of the can
	glColor3f(0.0, 0.0, 0.0);

	gluCylinder(qobj, rad, rad, height, 5, 3);
	glTranslatef(0.0, 0.0, height/4);

	//make the rim of the can
	glColor3f(0.0, 0.0, 1.0);
	gluCylinder(qobj, rad /2, rad/2, 3, 5, 3);
	glTranslatef(0.0, 0.0, height /2);



	//make the top part of the can
	glColor3f(0.0, 0.0, 0.0);
	gluSphere(qobj, 1, 10, 5);
	glTranslatef(0.0, 0.0, height + 2.5);

	glEndList();


	/*glBegin(GL_QUADS);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(40.0, -50.0, 0.0);
	glVertex3f(40.0, -50.0, 3.0);

	glEnd();*/

	initialized = true;
	return true;
}

void Trash::draw() {
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);
	glCallList(displayList);
	glPopMatrix();
}