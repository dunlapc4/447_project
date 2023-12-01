#include "Tree.h"
#include "libtarga.h"


Tree::Tree()
{ 
		displayList = 0; 
		initialized = false; 
		height = 10.0; 
		baseRad = 10.0; 
		topRad = 0.3;  
		coord[0] = coord[1] = coord[2] = 0.0f; 
		}

Tree::Tree(GLdouble theHeight, GLdouble theBase, GLdouble theTop, float x, float y, float z) {

	displayList = 0; 
	initialized = false;
	height = theHeight; 
	baseRad = theBase;
	topRad = theTop;
	
	
	coord[0] = x;
	coord[1] = y;
	coord[2] = z;

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
	glNewList(displayList, GL_COMPILE);

	//now make the shapes 

	//trunk
	glColor3f(0.50, 0.30, 0.07);
	//referenced and modified from these values for brown (0.5f, 0.35f, 0.05f)

	gluCylinder(qobj, baseRad /2 , topRad /2, height / 3, 9, 10);
	glTranslatef(0.0, 0.0, height);

	//leaves
	glColor3f(0.0, 0.5, 0.0);
	glTranslatef(0.0, 0.0, height / 10);
	//tree currently is coming out weird and not connecting to the base. Maybe if I do it in segments it will connect. I will look into this
	for (int i = 4; i > 1; --i) { 
		//I need to make the base radius wider otherwise it comes out too skinny
		//I also also I need to subtract our current 'i' value it otherwise it will become too wide
		gluCylinder(qobj, baseRad   *2  - ((float)i), 0, height, 9, 10);
		//i cannot just have the base Radius widen it needs to be modified by something i think
		glTranslatef(0.0, 0.0, -(height / 2)); //move down to the next part 
	}


	glEndList();

	
	
	initialized = true;

	return true;
}

void Tree::draw() { //unsure if initialize function is breaking but deff when i leave the draw in currently it is having issues
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);
	glCallList(displayList);
	glPopMatrix() ;
}