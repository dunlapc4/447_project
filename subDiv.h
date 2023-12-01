#include <FL/gl.h>
#include <FL/glu.h>


class subDiv {
private:
	GLubyte displayList;
	GLubyte displayList2;

	GLdouble height;
	GLdouble width;
	GLdouble length;
	bool initialized;
	float coord[3];
	Point point[4];

public:
	subDiv() { displayList = 0; displayList2 = 0;  height = 0; width = 0; length = 0;  initialized = false; coord[0] = coord[1] = coord[2]; }
	subDiv(GLdouble theHeight, GLdouble theWidth, GLdouble theLength, float x, float y, float z);
	~subDiv();

	bool initialize();
	void draw(int sdVal);

};


struct Point {
	Point() { x = 0; y = 0; z = 0; }
	float x;
	float y;
	float z;
};