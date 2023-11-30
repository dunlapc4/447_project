/*
 * CS559 Maze Project
 *
 * Class file for the WorldWindow class.
 *
 * (c) Stephen Chenney, University of Wisconsin at Madison, 2001-2002
 *
 */

#include "WorldWindow.h"
#include <Fl/math.h>
#include <Fl/gl.h>
#include <GL/glu.h>
#include <stdio.h>

const double WorldWindow::FOV_X = 45.0;

WorldWindow::WorldWindow(int x, int y, int width, int height, char *label)
	: Fl_Gl_Window(x, y, width, height, label)
{
    button = -1;

    // Initial viewing parameters.
    phi = 45.0f;
    theta = 0.0f;
    dist = 100.0f;
    x_at = 0.0f;
    y_at = 0.0f;

	int wallLength = 100;
	int maxDist = 48;
	int wallHeight = 8;
	int wallWidth = 2;
	north = new Wall(wallHeight, wallWidth, wallLength, maxDist, 0, 0);
	east = new Wall(wallHeight, wallWidth, wallLength, maxDist, 0, 0);
	south = new Wall(wallHeight, wallWidth, wallLength, -maxDist, 0, 0);
	west = new Wall(wallHeight, wallWidth, wallLength, -maxDist, 0, 0);

	//values for the tree implementation 
	float theHeight = 10.0;
	float theBase = 3.0;
	float theTop = 3.0;


	//(GLdouble theHeight, GLdouble theBase, GLdouble theTop, float x, float y, float z)
	tree = new Tree(theHeight, theBase, theTop, 30.0, 20.0, 0.0); //test to see if we can actually make the tree draw
	//since we need to make varrying forms of the trees maybe I can try an array of them or a few arrays so that they are varried groups
	for (int i = 0; i < 10; ++i) {
		int heightRand = rand() % 5;
		int baseRand = rand() % 3; //I do not think I need to rand the base

		int xval = -40.0f + (rand() % 100);
		int yval = -40.0f + (rand() % 10);

		trees[i] = new Tree(theHeight + heightRand, theBase, theTop+baseRand, xval, yval, 0.0f);

		//float trashHeight = 5.0;
		//float trashRad = 2.0;
		float myX[4] = { 1.0, 1.0, -1.0, -1.0 };
		float myY[4] = { 1.0, -1.0, -1.0, 1.0 };
		float myZ[4] = { 0.0, 0.0, 0.0, 0.0 };

		can = new Trash(myX, myY, myZ);

		ride = new Wheel(-30.0, 20.0, 0.0f);
	}
}


void
WorldWindow::draw(void)
{
    double  eye[3];
    float   color[4], dir[4];

    if ( ! valid() )
    {
	// Stuff in here doesn't change from frame to frame, and does not
	// rely on any coordinate system. It only has to be done if the
	// GL context is damaged.

	double	fov_y;

	// Sets the clear color to sky blue.
	glClearColor(0.53f, 0.81f, 0.92f, 1.0);

	// Turn on depth testing
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// Turn on back face culling. Faces with normals away from the viewer
	// will not be drawn.
	glEnable(GL_CULL_FACE);

	// Enable lighting with one light.
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	// Ambient and diffuse lighting track the current color.
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	// Turn on normal vector normalization. You don't have to give unit
	// normal vector, and you can scale objects.
	glEnable(GL_NORMALIZE);

	// Set up the viewport.
	glViewport(0, 0, w(), h());

	// Set up the persepctive transformation.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	fov_y = 360.0f / M_PI * atan(h() * tan(FOV_X * M_PI / 360.0) / w());
	gluPerspective(fov_y, w() / (float)h(), 1.0, 1000.0);

	// Do some light stuff. Diffuse color, and zero specular color
	// turns off specular lighting.
	color[0] = 1.0f; color[1] = 1.0f; color[2] = 1.0f; color[3] = 1.0f;
	glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
	color[0] = 0.0f; color[1] = 0.0f; color[2] = 0.0f; color[3] = 1.0f;
	glLightfv(GL_LIGHT0, GL_SPECULAR, color);

	// Initialize all the objects.
	ground.Initialize();
	traintrack.Initialize();

	north->Initialize();
	east->Initialize();
	south->Initialize();
	west->Initialize();
	tree->initialize();
	for (int i = 0; i < 10; ++i) {
		trees[i]->initialize();
	}
	can->initialize();

	ride->initialize();
	
    }

    // Stuff out here relies on a coordinate system or must be done on every
    // frame.

    // Clear the screen. Color and depth.
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Set up the viewing transformation. The viewer is at a distance
    // dist from (x_at, y_ay, 2.0) in the direction (theta, phi) defined
    // by two angles. They are looking at (x_at, y_ay, 2.0) and z is up.
    eye[0] = x_at + dist * cos(theta * M_PI / 180.0) * cos(phi * M_PI / 180.0);
    eye[1] = y_at + dist * sin(theta * M_PI / 180.0) * cos(phi * M_PI / 180.0);
    eye[2] = 2.0 + dist * sin(phi * M_PI / 180.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye[0], eye[1], eye[2], x_at, y_at, 2.0, 0.0, 0.0, 1.0);

    // Position the light source. This has to happen after the viewing
    // transformation is set up, so that the light stays fixed in world
    // space. This is a directional light - note the 0 in the w component.
    dir[0] = 1.0; dir[1] = 1.0; dir[2] = 1.0; dir[3] = 0.0;
    glLightfv(GL_LIGHT0, GL_POSITION, dir);

    // Draw stuff. Everything.
    ground.Draw();
    traintrack.Draw();

	west->Draw();
	east->Draw();

	glRotatef(90, 0, 0, 1);

	north->Draw();
	south->Draw();
	tree->draw();
	for (int i = 0; i < 10; ++i) {
		trees[i]->draw();
	}

	can->draw();

	//glRotatef(90, 0, 0, 1);
	ride->draw();
//	ride->draw();
}


void
WorldWindow::Drag(float dt)
{
    int	    dx = x_down - x_last;
    int     dy = y_down - y_last;

    switch ( button )
    {
      case FL_LEFT_MOUSE:
	// Left button changes the direction the viewer is looking from.
	theta = theta_down + 360.0f * dx / (float)w();
	while ( theta >= 360.0f )
	    theta -= 360.0f;
	while ( theta < 0.0f )
	    theta += 360.0f;
	phi = phi_down + 90.0f * dy / (float)h();
	if ( phi > 89.0f )
	    phi = 89.0f;
	if ( phi < -5.0f )
	    phi = -5.0f;
	break;
      case FL_MIDDLE_MOUSE:
	// Middle button moves the viewer in or out.
	dist = dist_down - ( 0.5f * dist_down * dy / (float)h() );
	if ( dist < 1.0f )
	    dist = 1.0f;
	break;
      case FL_RIGHT_MOUSE: {
	// Right mouse button moves the look-at point around, so the world
	// appears to move under the viewer.
	float	x_axis[2];
	float	y_axis[2];

	x_axis[0] = -(float)sin(theta * M_PI / 180.0);
	x_axis[1] = (float)cos(theta * M_PI / 180.0);
	y_axis[0] = x_axis[1];
	y_axis[1] = -x_axis[0];

	x_at = x_at_down + 100.0f * ( x_axis[0] * dx / (float)w()
				    + y_axis[0] * dy / (float)h() );
	y_at = y_at_down + 100.0f * ( x_axis[1] * dx / (float)w()
				    + y_axis[1] * dy / (float)h() );
	} break;
      default:;
    }
}


bool
WorldWindow::Update(float dt)
{
    // Update the view. This gets called once per frame before doing the
    // drawing.

    if ( button != -1 ) // Only do anything if the mouse button is down.
	Drag(dt);

    // Animate the train.
    traintrack.Update(dt);

	ride->update(dt);   ///this here is the update function for world window i put the update func for wheel here

    return true;
}


int
WorldWindow::handle(int event)
{
    // Event handling routine. Only looks at mouse events.
    // Stores a bunch of values when the mouse goes down and keeps track
    // of where the mouse is and what mouse button is down, if any.
    switch ( event )
    {
      case FL_PUSH:
        button = Fl::event_button();
	x_last = x_down = Fl::event_x();
	y_last = y_down = Fl::event_y();
	phi_down = phi;
	theta_down = theta;
	dist_down = dist;
	x_at_down = x_at;
	y_at_down = y_at;
	return 1;
      case FL_DRAG:
	x_last = Fl::event_x();
	y_last = Fl::event_y();
	return 1;
      case FL_RELEASE:
        button = -1;
	return 1;
    }

    // Pass any other event types on the superclass.
    return Fl_Gl_Window::handle(event);
}


