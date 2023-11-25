#include "Tree.h"
#include "libtarga.h"
#include <stdio.h>

/*Tree::Tree() {
	//
}*/

Tree::Tree(void)
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

  
	//initialized = true;
	return true;
}


void Tree::Draw(void) {


}