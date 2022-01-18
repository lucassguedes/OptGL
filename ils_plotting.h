#ifndef __ILS_PLOTTING_HPP__
#define __ILS_PLOTTING_HPP__

#include "optgl.h"
#include <stdio.h>

double g_originX;
double g_originY;
double g_window_width;
double g_window_height;
double g_upper_bound;

double ilsPlottingGetCartesianPrecision(double axisMax);

double ilsPlottingDrawLine(double x0, double y0, double x1, double y1);


double ilsPlottingDrawPoint(double x, double y);


void ilsPlottingDrawCartesian(double screenWidth, double screenHeight, double originX, double originY, double maxX, double maxY);




#endif

