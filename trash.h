#include <FL/gl.h>
#include <FL/glu.h>


/*thoughts for this one is to basically make a cylindar with a spherical lid to make the sweep object. 
Since I do not know if making the trees the way I did would count 
I need to make it not using the cylindar function I think but I am not sure*/

struct Point {
	Point() { x = 0; y = 0; z = 0; }
	//Point(int x, int y, int z);
	float x;
	float y;
	float z;
};

class Trash {
private:
	/*GLdouble height;
	GLdouble base;
	GLdouble width;
	GLdouble length;
	GLdouble height;*/
	bool initialized;
	GLubyte displayList; 
	//float coord[3];
	Point point[4];
	//GLUquadric* qobj;
	

public:

	Trash();
	Trash( float x[4], float y[4], float z[4]);

	~Trash();

	bool initialize();
	void draw();
};


