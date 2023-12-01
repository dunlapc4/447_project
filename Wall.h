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
	Wall();
	Wall(GLdouble theHeight, GLdouble theWidth, GLdouble theLength, float x, float y, float z);
	~Wall();

	bool Initialize();
	void Draw();
};