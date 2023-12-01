#include "subDiv.h"

/*subDiv::SubDiv()
{ displayList = 0;
 displayList2 = 0; 
  height = 0; 
  width = 0; 
  length = 0;  
  initialized = false; coord[0] = coord[1] = coord[2]; 
  }*/

subDiv::subDiv(GLdouble theHeight, GLdouble theWidth, GLdouble theLength, float x, float y, float z, float ax[4], float ay[4], float az[4]) {
	displayList = 0;
	displayList2 = 0;
	initialized = false;
	height = theHeight;
	width = theWidth;
	length = theLength;
	coord[0] = x;
	coord[1] = y;
	coord[2] = z;

	for (int i = 0; i < 4; ++i) {
		point[i].x = ax[i];
		point[i].y = ay[i];
		point[i].z = az[i];
	}

}

subDiv::~subDiv() {
	if (initialized) {
		glDeleteLists(displayList, 1);
		glDeleteLists(displayList2, 1);
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
	

	//-----------------------------------------------------
	//glvertexf(x, y z);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3f(-width / 2, length / 2, height);
	glVertex3f(-width / 2, -length / 2, height);
	glVertex3f(width / 2, -length / 2, height);
	glVertex3f(width / 2, length / 2, height);

	{}

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
	glVertex3f(width/2, length/2, height);
	glVertex3f(width/2, length/2, 0.0f); //back wall
	glVertex3f(-width/2, length/2, 0.0f);
	glVertex3f(-width/2, length/2, height);

   /* glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, 1.0f); 
    glVertex3f(0.5f, 0.5f, 0.0f); //back wall
    glVertex3f(-0.5f, 0.5f, 0.0f);
    glVertex3f(-0.5f, 0.5f, 1.0f);

    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.0f);
    glVertex3f(0.5f, -0.5f, 1.0f); //front wall
    glVertex3f(-0.5f, -0.5f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.0f);*/
	//------------------------------------------------------

	glEnd();

	glEndList();

	displayList2 = glGenLists(1);
	glNewList(displayList2, GL_COMPILE);
	// Use white, because the texture supplies the color.
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_QUADS);

		//do subdivision of points here
	//figure out how to mathmatically modify the cube i have 
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 4; i++) {
			//glNormal3f(0.0, 0.0, 1.0);
			//glRotatef(90.0, 1.0, 0.0f, 0.0f);
			glVertex3f(point[i].x, point[i].y, point[i].z);
			glVertex3f(point[i].x, point[i].y, point[i].z + j);
			glVertex3f(point[(i + 1) % 4].x, point[(i + 1) % 4].y, point[i].z + j);
			glVertex3f(point[(i + 1) % 4].x, point[(i + 1) % 4].y, point[i].z);
			//glVertex3f(point[i].x, point[i].y, point[i].z+base[i]);
		}
	}

	glEnd();
	glEndList();

	initialized = true;
	return true;
}

void subDiv::draw(int sdVal) {
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);
	if (sdVal == 1) {
		glCallList(displayList2);
	}
	else {
		glCallList(displayList);

	}
	glPopMatrix();
}

