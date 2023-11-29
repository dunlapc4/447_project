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
	glNormal3f(0.0, 0.0, 1.0);
	
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.1);
	glVertex3f(1.0, 10.0, 0.0);
	
	glVertex3f(-1.0, 1.0, 0.0);

	glVertex3f(-1.0, -1.0, 0.0);

	glVertex3f(1.0, -1.0, 0.0);
	glEnd();


	glColor3f(0.2, 0.2, 0.2);

	float base[4] = { 0.2, 0.3, -0.1, -0.3 };
	glBegin(GL_QUADS);  
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 4; i++) { 
			//glNormal3f(0.0, 0.0, 1.0);
			//glRotatef(90.0, 1.0, 0.0f, 0.0f);
			glVertex3f(point[i].x, point[i].y, point[i].z);
			glVertex3f(point[i].x, point[i].y, point[i].z + j);
			glVertex3f(point[(i + 1) % 4].x, point[(i + 1) % 4].y, point[i].z + j);
			glVertex3f(point[(i + 1) % 4].x, point[(i+1)  % 4].y, point[i].z);
			//glVertex3f(point[i].x, point[i].y, point[i].z+base[i]);
		}
	}
	glColor3f(1.0, 0.9, 0.0);
	glNormal3f(0.0, 0.0, 1.0);

	for (int j = 0; j < 3; ++j) {
		for (int i = 0; i < 4; ++i) {
			glVertex3f(point[i].x, point[i].y, point[i].z);
			glVertex3f(point[i].x*base[i], point[i].y*base[i], (point[i].z + base[i]) +j);
			glVertex3f(point[(i + 1) % 4].x*base[i], point[(i + 1) % 4].y*base[i], (point[i].z + base[i]) + j);
			glVertex3f(point[(i + 1) % 4].x*base[i], point[(i + 1) % 4].y * base[i], point[i].z + base[i]);


		}
	}
	
	glColor3f(1.0, 0.2, 0.0);
	glNormal3f(0.0, 0.0, 1.0);

	for (int j = 0; j < 6; ++j) {
		for (int i = 0; i < 4; ++i) {
			glVertex3f(point[i].x, point[i].y, point[i].z);
			glVertex3f(point[i].x * base[i], point[i].y * base[i], (point[i].z + base[i]) + j);
			glVertex3f(point[(i + 1) % 4].x * base[i], point[(i + 1) % 4].y * base[i], (point[i].z + base[i]) + j);
			glVertex3f(point[(i + 1) % 4].x * 0.5, point[(i + 1) % 4].y * -0.5, point[i].z + 0.6);


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