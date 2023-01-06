#ifndef __GRAPHICS_UTILS__H
#define __GRAPHICS_UTILS__H
#include <GL/glut.h>
#include "graph.h"
#include "point.h"
#include "cartesian.h"

class Window{
    private:
        int width;
        int height;

    public:

    Window(int argc, char ** argv, const int width, const int height);

    void draw_figure(Graph graph);
    void main_loop();
    void clear();

    void draw_text(char * string, int x, int y);
    void draw_large_text(char * string, int x, int y);

    void draw_figure(Cartesian cartesian);

    void draw_function(Cartesian cartesian, std::vector<tPoint> coords);
    void draw_line(Cartesian cartesian, double x0, double y0, double x1, double y1);
};




#endif