#include "Wall.h"
#include "libtarga.h"
#include <stdio.h>

Wall::~Wall() {
	if (initialized) {
		glDeleteLists(displayList, 1);
		gluDeleteQuadric(qobj);
		glDeleteTextures(1, &texture_obj);

	}
}

Wall::Wall(GLdouble theHeight, GLdouble theWidth, GLdouble theLength, float x, float y, float z) {
	displayList = 0;
	initialized = false;
	height = theHeight;
	length = theLength;
	width = theWidth;
	coord[0] = x;
	coord[1] = y;
	coord[2] = z;
}



bool Wall::Initialize() {
	//code goes here 
	ubyte* image_data;
	int	    image_height, image_width;

	// Load the image for the texture. The texture file has to be in
	// a place where it will be found.
	if (!(image_data = (ubyte*)tga_load("wall.tga", &image_width,
		&image_height, TGA_TRUECOLOR_24)))
	{
		fprintf(stderr, "Ground::Initialize: Couldn't load wall.tga\n");
		return false;
	}

	// This creates a texture object and binds it, so the next few operations
	// apply to this texture.
	glGenTextures(1, &texture_obj);
	glBindTexture(GL_TEXTURE_2D, texture_obj);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// This sets up the texture with high quality filtering. First it builds
	// mipmaps from the image data, then it sets the filtering parameters
	// and the wrapping parameters. We want the grass to be repeated over the
	// ground.
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image_width, image_height,
		GL_RGB, GL_UNSIGNED_BYTE, image_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
		GL_NEAREST_MIPMAP_LINEAR);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// Now do the geometry. Create the display list.
	displayList = glGenLists(1);
	glNewList(displayList, GL_COMPILE);
	// Use white, because the texture supplies the color.
	glColor3f(1.0, 1.0, 1.0);

	// The surface normal is up for the ground.
	//glNormal3f(0.0, 0.0, 1.0);

	// Turn on texturing and bind the grass texture.
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture_obj);

	// Draw the ground as a quadrilateral, specifying texture coordinates.
	glBegin(GL_QUADS);

	//more to go
	//I think i can use a similar but modified approach that was used in ground.cpp

	//-----------------------------------------------------
	
		glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0, 0.0); // texture
	glVertex3f(-width / 2, length / 2, height);
	glTexCoord2f(0.0, 1.0); // texture
	glVertex3f(-width / 2, -length / 2, height);
	glTexCoord2f(1.0, 1.0); //texture
	glVertex3f(width / 2, -length / 2, height);
	glTexCoord2f(1.0, 0.0); //texture
	glVertex3f(width / 2, length / 2, height); 

	
	

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0, 0.0); // texture
	glVertex3f(-width / 2, -length / 2, 0.0f);
	glTexCoord2f(0.0, 1.0); // texture
	glVertex3f(-width / 2, -length / 2, height);
	glTexCoord2f(1.0, 1.0); //texture
	glVertex3f(-width / 2, length / 2, height);
	glTexCoord2f(1.0, 0.0); //texture
	glVertex3f(-width / 2, length / 2, 0.0f);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(1.0, 0.0); //texture
	glVertex3f(width / 2, length / 2, 0.0f);
	glTexCoord2f(1.0, 1.0); //texture
	glVertex3f(width / 2, length / 2, height);
	glTexCoord2f(0.0, 1.0); // texture
	glVertex3f(width / 2, -length / 2, height);
	glTexCoord2f(0.0, 0.0); // texture
	glVertex3f(width / 2, -length / 2, 0.0f);

	
	//------------------------------------------------------

	glEnd();
	glDisable(GL_TEXTURE_2D);

	glEndList();

	initialized = true;
	return true;
}

void Wall::Draw() {
	//draw the wall object
	glPushMatrix();
	glTranslatef(coord[0], coord[1], coord[2]);
	//glRotatef(90, 0, 0, 1);

	glCallList(displayList);
	glPopMatrix();
}


//extrapolate from the following code on how to texture the wall
/* ubyte   *image_data;
    int	    image_height, image_width;

    // Load the image for the texture. The texture file has to be in
    // a place where it will be found.
    if ( ! ( image_data = (ubyte*)tga_load("grass.tga", &image_width,
					   &image_height, TGA_TRUECOLOR_24) ) )
    {
	fprintf(stderr, "Ground::Initialize: Couldn't load grass.tga\n");
	return false;
    }

    // This creates a texture object and binds it, so the next few operations
    // apply to this texture.
    glGenTextures(1, &texture_obj);
    glBindTexture(GL_TEXTURE_2D, texture_obj);*/

