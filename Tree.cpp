#include "Tree.h"
#include "libtarga.h"



Tree::Tree(GLdouble theHeight, GLdouble theBase, float x, float y, float z) {

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

	initialized = true;
	return true;
}

void Tree::draw() {
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);
	glCallList(displayList);
	glPopMatrix;
}