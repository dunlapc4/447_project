#include "trash.h"


Trash::Trash(float x[4], float y[4], float z[4]) {
	for (int i= 0; i < 4; i++) {
		point[i].x = x[i];
		point[i].y = y[i];
		point[i].z = z[i];
	}
}
//make overloaded constructors one default and one input
Trash::~Trash() {
	if (initialized) {
		glDeleteLists(displayList, 1);
		//gluDeleteQuadric(qobj);
	}
}

bool Trash::initialize() {
	//this is going to initialize the object by building it from scratch and not using the glCylindar command 
	//qobj = gluNewQuadric();
	//gluQuadricNormals(qobj, GLU_SMOOTH);
	displayList = glGenLists(1);
	glNewList(displayList, GL_COMPILE);
	//glNormal3f(1.0, 0.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);

	float height[4] = { 0.5, 0.5, -0.5, -0.5 };
	glBegin(GL_QUADS);  
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 4; i++) { //this works but it is too large 
			//glNormal3f(0.0, 0.0, 1.0);
			//glRotatef(90.0, 1.0, 0.0f, 0.0f);
			glVertex3f(point[i].x, point[i].y, point[i].z);
			glVertex3f(point[i].x, point[i].y, point[i].z + j);
			glVertex3f(point[(i + 1) % 4].x, point[(i + 1) % 4].y, point[i].z + j);
			glVertex3f(point[(i + 1) % 4].x, point[(i+1)  % 4].y, point[i].z);
			glVertex3f(point[i].x * height[i], point[i].y, point[i].z);
		}
	}
	

	glEnd();
	glEndList();

	initialized = true;
	return true;
}

void Trash::draw() {
	glPushMatrix();
	//glTranslatef(coord[0], coord[1], coord[2]);
	for (int i = 0; i < 4; ++i) {
		glTranslatef(point[i].x, point[i].y, point[i].z);
	}
	glCallList(displayList);
	glPopMatrix();
}