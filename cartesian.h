#ifndef __CARTESIAN_H__
#define __CARTESIAN_H__
#include "optgl.h"
#include <stdio.h>


#define VALUE_INDICATOR_LINE_HALF_SIZE 0.005
#define AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR 0.01 
#define Y_AXIS_SIZE_IN_PIXELS 500
#define X_AXIS_SIZE_IN_PIXELS 1000


#define UPPER_BOUND_FACTOR 50

class Cartesian{
    private:
        tPoint origin;

        double window_width;
        double window_height;

        double x_upperbound;
        double y_upperbound;



    double getCartesianAxisPrecision(double axisMax);



    public:

    double drawLine(double x0, double y0, double x1, double y1);

    Cartesian(double window_width, double window_height, tPoint origin);

    void draw_cartesian(tPoint origin, double x_max, double y_max);

};



#endif