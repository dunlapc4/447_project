#include <FL/gl.h>
#include <FL/glu.h>
#include <FL/glut.H>

class Wheel {
private:
	bool initialized;
	GLubyte displayList[2];
	GLUquadric* qobj;
	double base;
	double top;
	float coord[3];


public:
	Wheel() { displayList[0] = 0; displayList[1] = 0; initialized = false; coord[0] = coord[1] = coord[2]; }
	Wheel(float x, float y, float z);
	~Wheel();

	bool initialize();
	void draw();

	void update(float updateVal);
};
