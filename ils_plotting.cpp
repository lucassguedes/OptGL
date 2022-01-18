#include "ils_plotting.h"
#include <iostream>

#define VALUE_INDICATOR_LINE_HALF_SIZE 0.005
#define AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR 0.01 
#define Y_AXIS_SIZE_IN_PIXELS 500
#define X_AXIS_SIZE_IN_PIXELS 1000

double ilsPlottingGetCartesianPrecision(double axisMax){
    std::cout  << "axisMax:" << axisMax << std::endl;
    if(axisMax < 100)
        return 5; 
    else if(axisMax < 1000)
        return 10;
    return 1000; 
}


double ilsPlottingDrawLine(double x0, double y0, double x1, double y1){
    double x0coord = g_originX + (X_AXIS_SIZE_IN_PIXELS*x0)/(140);
    double y0coord = g_originY + (Y_AXIS_SIZE_IN_PIXELS)*(y0/(g_upper_bound));

    double x1coord = g_originX + (X_AXIS_SIZE_IN_PIXELS*x1)/(140);
    double y1coord = g_originY + (Y_AXIS_SIZE_IN_PIXELS)*(y1/(g_upper_bound));

    if(x1coord <= g_originX + X_AXIS_SIZE_IN_PIXELS && y1coord <= g_originY + Y_AXIS_SIZE_IN_PIXELS){

        if(y0coord > g_originY + Y_AXIS_SIZE_IN_PIXELS)
            y0coord = g_originY + Y_AXIS_SIZE_IN_PIXELS;


        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
            glVertex2f(x0coord, y0coord);
            glVertex2f(x1coord, y1coord);
        glEnd();

        glFlush();
    }

}

double ilsPlottingDrawPoint(double x, double y){
    glPointSize(10);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
        glVertex2f(g_originX +x, g_originY + y); 
    glEnd();

    glFlush();
}

void ilsPlottingDrawCartesian(double screenWidth, double screenHeight, double originX, double originY, double maxX, double maxY){

    glLineWidth(1.5);
    glColor3f(0.0, 0.0, 0.0);

    g_upper_bound = 50 * maxY;

    g_originX = originX;
    g_originY = originY;

    g_window_width = screenWidth;
    g_window_height = screenHeight;



    double xAxisMax = X_AXIS_SIZE_IN_PIXELS;
    double yAxisMax = Y_AXIS_SIZE_IN_PIXELS;

    double xPrecision = ilsPlottingGetCartesianPrecision(maxX);
    double yPrecision = ilsPlottingGetCartesianPrecision(g_upper_bound);

    
    double xStep = xPrecision*(xAxisMax/maxX);
    double yStep = yPrecision*(yAxisMax/maxY);


    //Drawing the x axis
    glBegin(GL_LINES);
        glVertex2f(originX, originY);
        glVertex2f(originX + xAxisMax, originY); 
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(originX + xAxisMax, originY - AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR*screenHeight);
        glVertex2f(originX + xAxisMax, originY + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR*screenHeight);
        glVertex2f(originX + xAxisMax + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR*screenWidth, originY);
    glEnd();

    //Drawing the y axis
    glBegin(GL_LINES);
        glVertex2f(originX, originY);
        glVertex2f(originX, originY + yAxisMax); 
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(originX - AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR*screenHeight, originY + yAxisMax);
        glVertex2f(originX  + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR*screenHeight, originY + yAxisMax);
        glVertex2f(originX,  originY + yAxisMax  + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR*screenWidth);
    glEnd();

    /*Drawing the x value indicators*/


    xStep = X_AXIS_SIZE_IN_PIXELS / 8;
    yStep = Y_AXIS_SIZE_IN_PIXELS / 8;

    xPrecision = maxX / 8;
    yPrecision = g_upper_bound / 8;



    for(int i = originX, j = 0; i < originX + xAxisMax; i+=xStep, j+=xPrecision){
        glBegin(GL_LINES);
            glVertex2f(i, originY - VALUE_INDICATOR_LINE_HALF_SIZE*screenHeight);
            glVertex2f(i, originY + VALUE_INDICATOR_LINE_HALF_SIZE*screenHeight);
        glEnd();

        char coordX[200];

        sprintf(coordX, "%d",j);

        optGLDrawText(coordX,i, originY - 0.02*screenHeight);
    }

    yPrecision = (yStep/Y_AXIS_SIZE_IN_PIXELS)*g_upper_bound; 

    /*Drawing the y value indicators*/
    for(int i = originY, j = 0; i < originY + yAxisMax; i+=yStep, j+=yPrecision){
        glBegin(GL_LINES);
            glVertex2f(originX - VALUE_INDICATOR_LINE_HALF_SIZE*screenHeight, i);
            glVertex2f(originX  + VALUE_INDICATOR_LINE_HALF_SIZE*screenHeight, i);
        glEnd();

        char coordY[200];

        sprintf(coordY, "%d",j);

        optGLDrawText(coordY, originX - 0.045*screenHeight, i);
    }

 
    /*Axis names*/
    char axisName[50];

    sprintf(axisName, "IterILS");
    
    optGLDrawTextLarge(axisName, originX + xAxisMax/2, originY - 0.1*screenHeight);


    sprintf(axisName, "Z");
    
    optGLDrawTextLarge(axisName, originX - 0.1*screenHeight, originY + yAxisMax/2);
    glFlush();
}