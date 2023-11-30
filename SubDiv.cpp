#include "subDiv.h"


subDiv::subDiv(GLdouble theHeight, GLdouble theWidth, GLdouble theLength, float x, float y, float z){
	displayList = 0;
	initialized = false;
	height = theHeight;
	width = theWidth;
	length = theLength;
	coord[0] = x;
	coord[1] = y;
	coord[2] = z;

}

subDiv::~subDiv() {
	if (initialized) {
		glDeleteLists(displayList, 1);
	}
}

bool subDiv::initialize() {

	displayList = glGenLists(1);
	glNewList(displayList, GL_COMPILE);
	// Use white, because the texture supplies the color.
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_QUADS);
	glRotatef(90, 0, 1, 0);
	//more to go
	//I think i can use a similar but modified approach that was used in ground.cpp
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-width / 2, length / 2, height);
	glVertex3f(-width / 2, -length / 2, height);
	glVertex3f(width / 2, -length / 2, height);
	glVertex3f(width / 2, length / 2, height);




	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3f(-width / 2, -length / 2, 0.0f);
	glVertex3f(-width / 2, -length / 2, height);
	glVertex3f(-width / 2, length / 2, height);
	glVertex3f(-width / 2, length / 2, 0.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(width / 2, length / 2, 0.0f);
	glVertex3f(width / 2, length / 2, height);
	glVertex3f(width / 2, -length / 2, height);
	glVertex3f(width / 2, -length / 2, 0.0f);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(width / 2, length / 2, 0.0f);
	glVertex3f(width / 2, length / 2, height);
	glVertex3f(width / 2, -length / 2, height);
	glVertex3f(width / 2, -length / 2, 0.0f);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(width / 2, length / 2, 0.0f);
	glVertex3f(width / 2, length / 2, height);
	glVertex3f(width / 2, -length / 2, height);
	glVertex3f(width / 2, -length / 2, 0.0f);




	/*/-----------------------------------------------------

    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 1.0f);
    glVertex3f(0.5f, -0.5f, 1.0f);

    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);

    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(0.5f, 0.5f, 1.0f);
    glVertex3f(0.5f, -0.5f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);

    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 1.0f);

    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 1.0f);

    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);
	//------------------------------------------------------*/

	glEnd();

	glEndList();

	initialized = true;
	return true;
}

void subDiv::draw() {
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);

	glCallList(displayList);
	glPopMatrix();
}
