#include "Tree.h"
#include "libtarga.h"
#include <stdio.h>

/*Tree::Tree() {
	//
}*/

Tree::Tree(void) {
    coord[0] = coord[1] = coord[2] = 0.0f;
    bool initialized = false;
    display_list = 0;
    height = 0.0;

    base = 0.0;
    //GLdouble   top;
}

Tree::Tree(GLdouble myHeight, GLdouble myBase, float x, float y, float z)
{ display_list = 0; 
initialized = false; 
height = 10.0; 
base = 3.0; 
coord[0] = coord[1] = coord[2] = 0.0f; }



Tree::~Tree(void)
{
    if (initialized)
    {
        glDeleteLists(display_list, 1);
        gluDeleteQuadric(qobj);
    }
}






bool Tree::Initialize(void) {
    
    qobj = gluNewQuadric();
    gluQuadricNormals(qobj, GLU_SMOOTH);
    display_list = glGenLists(1);

    glNewList(display_list, GL_COMPILE);

    //glRotatef(180.0f, 30.0f, 30.0f, 30.0f);
    glColor3f(0.54, 0.27, 0.07);
    gluCylinder(qobj, base/5, base/5, height/3, 10, 16);

    glColor3f(0.0, 1.0, 0.0);
    int treeHeight = height / 2;
    int treeComponents = 4;
    int spacing = 1;
    glTranslatef(0.0, 0.0, (height / 8 * treeComponents + 1));
    for (int i = treeComponents + 1; i > 1; --i) {
        gluCylinder(qobj, base * 2 - ((float)i / 1.5), 0, treeHeight, 10, 16);
        glTranslatef(0.0, 0.0, -(treeHeight / 2));
    }

    glEndList();
  
	initialized = true;
	return true;
}


void Tree::Draw(void) {

    glPushMatrix();

    // Translate the tree to the point
    glTranslatef(coord[0], coord[1], coord[2]);

    glCallList(display_list);
    glPopMatrix();

}