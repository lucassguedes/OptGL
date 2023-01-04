#ifndef __GRAPHICS_UTILS__H
#define __GRAPHICS_UTILS__H
#include <GL/glut.h>

class tPoint{
    public: 
    int node;
    double x;
    double y;

    tPoint(){}

    tPoint(double x, double y){
        this->x = x;
        this->y = y;
    }
};



void optGLDrawText(char * string, float x, float y);

void optGLDrawTextLarge(char * string, float x, float y);

void optGLClearScreen();

void optGLInit(int argc, char ** argv, double window_width, double window_height);

void optGLMainLoop();


#endif