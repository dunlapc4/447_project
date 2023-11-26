#include <FL/gl.h>
#include <FL/glu.h>


class Tree {
private:

	bool initialized;
	GLUquadric* qobj;
	//height and base but do we need several for base and etc
	GLdouble baseRad;
	GLdouble topRad;
	GLdouble height;
	GLdouble base;
	GLubyte  displayList;
	float coord[3];

public: 

	Tree() { displayList = 0; initialized = false; height = 10.0; base = 3.0;/*baseRad = 10.0; topRad = 0.3; */ coord[0] = coord[1] = coord[2] = 0.0f; }
	Tree(GLdouble theHeight, GLdouble theBase, float x, float y, float z);
	~Tree();

	bool initialize();

	void draw();
};