#include <FL/gl.h>
#include <FL/glu.h>
#include <FL/glut.H>

class Wheel {
private:
	bool initialized;
	GLubyte displayList;
	GLUquadric* qobj;
	double base;
	float coord[3];


public:
	Wheel();
	Wheel(float x, float y, float z);
	~Wheel();

	bool initialize();
	void draw();

	void update(float updateVal);
};
