#include "../include/cartesian.h"

Cartesian::Cartesian(double window_width, double window_height, tPoint origin)
{
    this->window_width = window_width;
    this->window_height = window_height;
    this->origin = origin;

    /*Default line color: red*/
    this->line_color_rgb[0] = 1.0;
    this->line_color_rgb[1] = 0.0;
    this->line_color_rgb[2] = 0.0;

    /*Default axis name*/
    this->horizontal_axis_name = "x";
    this->vertical_axis_name = "y";
}

double Cartesian::getCartesianAxisPrecision(double axisMax)
{
    if (axisMax < 100)
        return 5;
    else if (axisMax < 1000)
        return 10;
    return 1000;
}

void Cartesian::drawLine(double x0, double y0, double x1, double y1)
{
    double x0coord = this->origin.x + (X_AXIS_SIZE_IN_PIXELS * x0) / (this->x_upperbound / UPPER_BOUND_FACTOR);
    double y0coord = this->origin.y + (Y_AXIS_SIZE_IN_PIXELS) * (y0 / (this->y_upperbound));

    double x1coord = this->origin.x + (X_AXIS_SIZE_IN_PIXELS * x1) / (this->x_upperbound / UPPER_BOUND_FACTOR);
    double y1coord = this->origin.y + (Y_AXIS_SIZE_IN_PIXELS) * (y1 / (this->y_upperbound));

    if (x1coord <= this->origin.x + X_AXIS_SIZE_IN_PIXELS && y1coord <= this->origin.y + Y_AXIS_SIZE_IN_PIXELS)
    {

        if (y0coord > this->origin.y + Y_AXIS_SIZE_IN_PIXELS)
            y0coord = this->origin.y + Y_AXIS_SIZE_IN_PIXELS;

        glColor3f(this->line_color_rgb[0], this->line_color_rgb[1], this->line_color_rgb[2]);
        glBegin(GL_LINES);
        glVertex2f(x0coord, y0coord);
        glVertex2f(x1coord, y1coord);
        glEnd();

        glFlush();
    }
}

void Cartesian::draw_function(std::vector<tPoint> coords)
{
    double previous_x = coords[0].x;
    double previous_y = coords[0].y;

    for (size_t i = 1; i < coords.size(); i++)
    {
        this->drawLine(previous_x, previous_y, coords[i].x, coords[i].y);
        previous_x = coords[i].x;
        previous_y = coords[i].y;
    }
}

void Cartesian::draw_cartesian(tPoint origin, double x_max, double y_max)
{

    // glLineWidth(1.5);
    // glColor3f(0.0, 0.0, 0.0);

    // double xStep, yStep, x_value_increment, y_value_increment;

    // this->x_upperbound = UPPER_BOUND_FACTOR * x_max;
    // this->y_upperbound = UPPER_BOUND_FACTOR * y_max;

    // xStep = (X_AXIS_SIZE_IN_PIXELS / 8);
    // yStep = (Y_AXIS_SIZE_IN_PIXELS / 8);

    // x_value_increment = (1.0 / 8) * x_max;
    // y_value_increment = (1.0 / 8) * this->y_upperbound;

    // // Drawing the x axis
    // glBegin(GL_LINES);
    // glVertex2f(this->origin.x, this->origin.y);
    // glVertex2f(this->origin.x + X_AXIS_SIZE_IN_PIXELS, this->origin.y);
    // glEnd();

    // glBegin(GL_TRIANGLES);
    // glVertex2f(this->origin.x + X_AXIS_SIZE_IN_PIXELS, this->origin.y - AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->window_height);
    // glVertex2f(this->origin.x + X_AXIS_SIZE_IN_PIXELS, this->origin.y + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->window_height);
    // glVertex2f(this->origin.x + X_AXIS_SIZE_IN_PIXELS + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->window_width, this->origin.y);
    // glEnd();

    // // Drawing the y axis
    // glBegin(GL_LINES);
    // glVertex2f(this->origin.x, this->origin.y);
    // glVertex2f(this->origin.x, this->origin.y + Y_AXIS_SIZE_IN_PIXELS);
    // glEnd();

    // glBegin(GL_TRIANGLES);
    // glVertex2f(this->origin.x - AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->window_height, this->origin.y + Y_AXIS_SIZE_IN_PIXELS);
    // glVertex2f(this->origin.x + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->window_height, this->origin.y + Y_AXIS_SIZE_IN_PIXELS);
    // glVertex2f(this->origin.x, this->origin.y + Y_AXIS_SIZE_IN_PIXELS + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->window_width);
    // glEnd();

    // /*Drawing the x value indicators*/

    // for (int i = this->origin.x, j = 0; i < this->origin.x + X_AXIS_SIZE_IN_PIXELS; i += xStep, j += x_value_increment)
    // {
    //     glBegin(GL_LINES);
    //     glVertex2f(i, this->origin.y - VALUE_INDICATOR_LINE_HALF_SIZE * this->window_height);
    //     glVertex2f(i, this->origin.y + VALUE_INDICATOR_LINE_HALF_SIZE * this->window_height);
    //     glEnd();

    //     char coordX[200];

    //     sprintf(coordX, "%d", j);

    //     optGLDrawText(coordX, i, this->origin.y - 0.02 * this->window_height);
    // }

    // /*Drawing the y value indicators*/
    // for (int i = this->origin.y, j = 0; i < this->origin.y + Y_AXIS_SIZE_IN_PIXELS; i += yStep, j += y_value_increment)
    // {
    //     glBegin(GL_LINES);
    //     glVertex2f(this->origin.x - VALUE_INDICATOR_LINE_HALF_SIZE * this->window_height, i);
    //     glVertex2f(this->origin.x + VALUE_INDICATOR_LINE_HALF_SIZE * this->window_height, i);
    //     glEnd();

    //     char coordY[200];

    //     sprintf(coordY, "%d", j);

    //     optGLDrawText(coordY, this->origin.x - 0.045 * this->window_height, i);
    // }

    // /*Axis names*/
    // char axisName[50];

    // strcpy(axisName, this->horizontal_axis_name.c_str());

    // optGLDrawTextLarge(axisName, this->origin.x + X_AXIS_SIZE_IN_PIXELS / 2, this->origin.y - 0.1 * this->window_height);

    // strcpy(axisName, this->vertical_axis_name.c_str());
    // optGLDrawTextLarge(axisName, this->origin.x - 0.1 * this->window_height, this->origin.y + Y_AXIS_SIZE_IN_PIXELS / 2);
    // glFlush();
}

void Cartesian::set_line_color(double red, double green, double blue)
{
    this->line_color_rgb[0] = red;
    this->line_color_rgb[1] = green;
    this->line_color_rgb[2] = blue;
}