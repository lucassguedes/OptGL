#include "optgl.h"

void optGLDrawText(char * string, float x, float y)
{
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();

    glPushMatrix();
    // Posição no universo onde o texto será colocado          
    glRasterPos2f(x,y); 
    // Exibe caracter a caracter
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,*string++); 
    glPopMatrix();

}

void optGLDrawTextLarge(char * string, float x, float y)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    // Posição no universo onde o texto será colocado          
    glRasterPos2f(x,y); 
    // Exibe caracter a caracter
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++); 
    glPopMatrix();

}

void optGLClearScreen(){
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void optGLInit(int argc, char ** argv, double window_width, double window_height){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(window_width, window_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("ILS Plotting");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, window_width, 0.0f, window_height, 0.0f, 1.0f);


    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();

}

void optGLMainLoop(){
    glutMainLoop();
}