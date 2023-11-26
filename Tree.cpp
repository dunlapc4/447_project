#include "Tree.h"
#include "libtarga.h"



Tree::Tree(GLdouble theHeight, GLdouble theBase, GLdouble theTop, float x, float y, float z) {

	displayList = 0; 
	initialized = false;
	height = theHeight; 
	baseRad = theBase;
	topRad = theTop;
	
	GLubyte  displayList;
	float coord[3];

}



Tree::~Tree() {
	if (initialized) {
		glDeleteLists(displayList, 1);
		gluDeleteQuadric(qobj);
	}
}

bool Tree::initialize() {
	qobj = gluNewQuadric();
	gluQuadricNormals(qobj, GLU_SMOOTH);
	displayList = glGenLists(1);

	glColor3f(0.55, 0.27, 0.07);
	//now make the shapes 

	//trunk
	gluCylinder(qobj, baseRad, topRad, height, 10, 16);

	//leaves
	glColor3f(0.0, 0.5, 0.0);
	/*glTranslatef(0.0, 0.0, height);
	gluCylinder(qobj, baseRad * 2, 0, height, 10, 16);*/

	initialized = true;
	return true;
}

void Tree::draw() { //unsure if initialize function is breaking but deff when i leave the draw in currently it is having issues
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);
	glCallList(displayList);
	glPopMatrix;
}