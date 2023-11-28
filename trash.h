#include <FL/gl.h>
#include <FL/glu.h>


/*thoughts for this one is to basically make a cylindar with a spherical lid to make the sweep object. 
Since I do not know if making the trees the way I did would count */

class Trash {
private:
	GLdouble height;
	GLdouble rad;
	bool initialized;
	GLubyte displayList; 
	float coord[3];
	

public:

	Trash() { displayList = 0; initialize = false; height = 10.0; rad = 2.0; coord[0] = coord[1] = coord[2] = 0.0f; }
	Trash(GLdouble theHeight, GLdouble theRad, float x, float y, float z);
	//make overloaded constructors one default and one input
	~Trash();

	bool initialize();
	void draw();
};
