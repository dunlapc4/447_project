#include <FL/gl.h>
#include <FL/glu.h>

class Wheel {
private:
	bool initialized;
	GLubyte displayList;


public:
	Wheel();
	~Wheel();

	bool initialize();
	void draw();
};
