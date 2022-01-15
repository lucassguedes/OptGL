#include "ils_plotting.h"

double ilsPlottingGetCartesianPrecision(double axisMax){
    if(axisMax < 100)
        return 5;
    else if(axisMax < 1000)
        return 10;
    return 1000;
}


double ilsPlottingDrawLine(double x0, double y0, double x1, double y1){
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2f(g_originX + (500*x0)/140, g_originY + ((500/4)*y0)/(2579));
        glVertex2f(g_originX + (500*x1)/140, g_originY + ((500/4)*y1)/(2579));
    glEnd();

    glFlush();
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

    g_originX = originX;
    g_originY = originY;

    g_window_width = screenWidth;
    g_window_height = screenHeight;



    double xAxisMax = 500;
    double yAxisMax = 500;

    const double xPrecision = ilsPlottingGetCartesianPrecision(maxX);
    const double yPrecision = ilsPlottingGetCartesianPrecision(maxY);

    
    double xStep = xPrecision*(xAxisMax/maxX);
    double yStep = yPrecision*(yAxisMax/maxY);


    //Drawing the x axis
    glBegin(GL_LINES);
        glVertex2f(originX, originY);
        glVertex2f(originX + xAxisMax, originY); 
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(originX + xAxisMax, originY - 0.01*screenHeight);
        glVertex2f(originX + xAxisMax, originY + 0.01*screenHeight);
        glVertex2f(originX + xAxisMax + 0.01*screenWidth, originY);
    glEnd();

    //Drawing the y axis
    glBegin(GL_LINES);
        glVertex2f(originX, originY);
        glVertex2f(originX, originY + yAxisMax); 
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(originX - 0.01*screenHeight, originY + yAxisMax);
        glVertex2f(originX  + 0.01*screenHeight, originY + yAxisMax);
        glVertex2f(originX,  originY + yAxisMax  + 0.01*screenWidth);
    glEnd();


    for(int i = originX, j = 0; i < originX + xAxisMax; i+=xStep, j+=xPrecision){
        glBegin(GL_LINES);
            glVertex2f(i, originY - 0.005*screenHeight);
            glVertex2f(i, originY + 0.005*screenHeight);
        glEnd();

        char coordX[200];

        sprintf(coordX, "%d",j);

        optGLDrawText(coordX,i, originY - 0.02*screenHeight);
    }


    for(int i = originY, j = 0; i < originY + yAxisMax; i+=yStep, j+=yPrecision){
        glBegin(GL_LINES);
            glVertex2f(originX - 0.005*screenHeight, i);
            glVertex2f(originX  + 0.005*screenHeight, i);
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