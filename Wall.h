#include <FL/gl.h>
#include <FL/glu.h>


class Wall {
private:
	GLubyte displayList;
	GLdouble height;
	GLdouble width;
	GLuint  texture_obj;    // The object for the wall texture 
	bool    initialized;    // Whether or not we have been initialize
	GLdouble length;
	float coord[3];
	GLUquadric* qobj;

public:
	Wall() {displayList 0; initialized = false; height = 20.0; width = 20.0; length = 20.0; coord[0] = coord[1] = coord[2] = 0.0f}
	Wall(GLdouble theHeight, GLdouble theWidth, GLdouble theLength, float x, float y, float z);
	~Wall();

	bool Initialize();
	void Draw();
};