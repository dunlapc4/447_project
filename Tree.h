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
	GLubyte  displayList;
	float coord[3];

public: 

	Tree();
	Tree(GLdouble theHeight, GLdouble theBase, GLdouble theTop, float x, float y, float z);
	~Tree();

	bool initialize();

	void draw();
};