#include "Wall.h"
Wall::~Wall() {
	if (initialized) {
		glDeleteLists(displayList, 1);
		gluDeleteQuadric(qobj);
	}
}

Wall::Wall(GLdouble theHeight, GLdouble theWidth, GLdouble theLength, float x, float y, float z) {
	displayList = 0;
	initialized = false;
	height = theHeight;
	length = theLength;
	width = theWidth;
	coord[0] = x;
	coord[1] = y;
	coord[2] = z;
}



bool Wall::Initialize() {
	//code goes here 
	initialized = true;
	return true;
}

void Wall::Draw() {
	//draw the wall object
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);
	glCallList(displayList);
	glPopMatrix();
}

