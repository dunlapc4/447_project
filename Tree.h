#include <FL/gl.h>
#include <FL/glu.h>




class Tree {
	private: 
		float coord[3];
		bool initialized; 
		GLubyte display_list; 
		GLUquadric* qobj;
		GLdouble height;
		GLdouble base;
		//GLdouble   baseRadius;
		//GLdouble   topRadius;


	public:
		//Tree();
		~Tree();
		Tree(void);

	
	


		bool Initialize(void);
		void Draw(void);
		

};



