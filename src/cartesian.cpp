#include "../include/cartesian.h"

void Cartesian::set_origin(tPoint origin)
{
    this->origin = origin;
}

Cartesian::Cartesian(tPoint origin)
{
    /*Default line color: red*/
    this->line_color_rgb[0] = 1.0;
    this->line_color_rgb[1] = 0.0;
    this->line_color_rgb[2] = 0.0;

    /*Default axis name*/
    this->horizontal_axis_name = "x";
    this->vertical_axis_name = "y";

    this->origin = origin;
}

double Cartesian::getCartesianAxisPrecision(double axisMax)
{
    if (axisMax < 100)
        return 5;
    else if (axisMax < 1000)
        return 10;
    return 1000;
}

void Cartesian::set_bounds(const int x, const int y)
{
    this->x_upperbound = UPPER_BOUND_FACTOR * x;
    this->y_upperbound = UPPER_BOUND_FACTOR * y;
}

void Cartesian::set_line_color(double red, double green, double blue)
{
    this->line_color_rgb[0] = red;
    this->line_color_rgb[1] = green;
    this->line_color_rgb[2] = blue;
}