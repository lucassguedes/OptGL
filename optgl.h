#ifndef __GRAPHICS_UTILS__H
#define __GRAPHICS_UTILS__H
#include <GL/glut.h>

typedef struct pointCoords{
    int node;
    double x;
    double y;
}tPointCoords;



void optGLDrawText(char * string, float x, float y);

void optGLDrawTextLarge(char * string, float x, float y);

void optGLClearScreen();

void optGLInit(int argc, char ** argv, double window_width, double window_height);

void optGLMainLoop();


#endif