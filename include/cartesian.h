#ifndef __CARTESIAN_H__
#define __CARTESIAN_H__
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include "point.h"


#define VALUE_INDICATOR_LINE_HALF_SIZE 0.005
#define AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR 0.01 
#define Y_AXIS_SIZE_IN_PIXELS 500.0
#define X_AXIS_SIZE_IN_PIXELS 500.0


#define UPPER_BOUND_FACTOR 50

class Cartesian{
    private:
    double getCartesianAxisPrecision(double axisMax);

    public:

    tPoint origin;
    double x_upperbound;
    double y_upperbound;
    double line_color_rgb[3];
    std::string vertical_axis_name;
    std::string horizontal_axis_name;

    void set_origin(tPoint origin);

    void set_bounds(const int x, const int y);

    void drawLine(double x0, double y0, double x1, double y1);

    void draw_function(std::vector<tPoint> coords);

    Cartesian(tPoint origin);

    void draw_cartesian(tPoint origin, double x_max, double y_max);

    void set_line_color(double red, double green, double blue);

};



#endif