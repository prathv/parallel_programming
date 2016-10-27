#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <omp.h>

#ifdef WIN32
#include <windows.h>
#endif

#ifdef WIN32
#include "glew.h"
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"
#include "glui.h"
#include “CL/cl.h"
#include “CL/cl_gl.h"


struct xyzw{float x, y, z, w;};
struct rgba{float r, g, b, a;};//Structures We Will Use to Fill the Vertex Buffers

size_t  GlobalWorkSize[3]  =  { NUM_PARTICLES, 1, 1 };
size_tLocalWorkSize[3]  =  { LOCAL_SIZE,         1, 1 };
gluinthPobj;// host opengl object for Points
gluinthCobj;// host opengl object for Colors
struct xyzw *hVel;// host C++ array for Velocities
cl_memdPobj;// device memory buffer for Points
cl_memdCobj;// device memory buffer for Colors
cl_memdVel;// device memory buffer for Velocities
cl_command_queueCmdQueue;
cl_device_idDevice;
cl_kernelKernel;
cl_platform_idPlatform;
cl_programProgram;

//random parameters

const float XMIN = { -100.0 }
const float XMAX = 	{  100.0 };
const float YMIN = 	{ -100.0 };
const float YMAX = 	{  100.0 };
const float ZMIN = 	{ -100.0 };
const float ZMAX = 	{  100.0 };

const float VMIN =	{   -100. };
const float VMAX =	{    100. };

const int NUM_PARTICLES = 1024*1024;
const int LOCAL_SIZE    = 32;
const char *CL_FILE_NAME   = { "particles.cl" };
const char *CL_BINARY_NAME = { "particles.nv" };


const int GLUITRUE  = { true  };
const int GLUIFALSE = { false };



const int INIT_WINDOW_SIZE = { 700 };		// window size in pixels

const float ANGFACT = { 1. };
const float SCLFACT = { 0.005f };
const float MINSCALE = { 0.001f };

const int LEFT   = { 4 };
const int MIDDLE = { 2 };
const int RIGHT  = { 1 };

enum Projections
{
	ORTHO,
	PERSP
};

enum ButtonVals
{
	GO,
	PAUSE,
	RESET,
	QUIT
};

const float BACKCOLOR[ ] = { 0., 0., 0., 0. };

const GLfloat AXES_COLOR[ ] = { 1., .5, 0. };
const GLfloat AXES_WIDTH   = { 3. };

struct xyzw
{
	float x, y, z, w;
};

struct rgba
{
	float r, g, b, a;
};

int	ActiveButton;		// current button that is down
GLuint	AxesList;		// list to hold the axes
int	AxesOn;			// ON or OFF
GLUI *	Glui;			// instance of glui window
int	GluiWindow;		// the glut id for the glui window
int	MainWindow;		// window id for main graphics window
int	Paused;
GLfloat	RotMatrix[4][4];	// set by glui rotation widget
float	Scale, Scale2;		// scaling factors
GLuint	SphereList;
int	WhichProjection;	// ORTHO or PERSP
int	Xmouse, Ymouse;		// mouse values
float	Xrot, Yrot;		// rotation angles in degrees
float	TransXYZ[3];		// set by glui translation widgets

double	ElapsedTime;
int		ShowPerformance;

size_t GlobalWorkSize[3] = { NUM_PARTICLES, 1, 1 };
size_t LocalWorkSize[3]  = { LOCAL_SIZE,    1, 1 };

GLuint			hPobj;
GLuint			hCobj;
cl_mem			dPobj;
cl_mem			dCobj;
struct xyzw *	hVel;
cl_mem			dVel;
cl_command_queue	CmdQueue;
cl_device_id		Device;
cl_kernel		Kernel;
cl_platform_id		Platform;
cl_program		Program;
cl_platform_id		PlatformID;

inline
float
SQR( float x )
{
	return x * x;
}

void	Animate( );
void	Axes( float );
void	Buttons( int );
void	Display( );
void	DoRasterString( float, float, float, char * );
void	DoStrokeString( float, float, float, float, char * );
void	InitCL( );
void	InitGlui( );
void	InitGraphics( );
void	InitLists( );
bool	IsCLExtensionSupported( const char * );
void	Keyboard( unsigned char, int, int );
void	MouseButton( int, int, int, int );
void	MouseMotion( int, int );
void	PrintCLError( cl_int, char * = "", FILE * = stderr );
void	Quit( );
float	Ranf( float, float );
void	Reset( );
void	ResetParticles( );
void	Resize( int, int );
void	Traces( int );
void	Visibility( int );

int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	InitGraphics();
	InitLists();
	InitCL();
	Reset();
	InitGlui();
	glutMainLoop();
	return 0 ;
}


