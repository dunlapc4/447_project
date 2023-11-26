#include <FL/gl.h>
#include <FL/glu.h>




class Tree {
	private: 
		float coord[3];
		bool initialized; 
		GLubyte display_list; 
		GLUquadric* qobj;
		GLdouble height;
		
		GLdouble   base;
		//GLdouble   top;


	public:
		//Tree();
		~Tree();
		Tree(GLdouble myHeight, GLdouble myBase, float x, float y, float z);
		Tree(void);

	
	


		bool Initialize(void);
		void Draw(void);
		

};



