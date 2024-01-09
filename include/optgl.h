#ifndef __GRAPHICS_UTILS__H
#define __GRAPHICS_UTILS__H
#include <GL/glut.h>
#include "math.h"
#include "graph.h"
#include "point.h"
#include "cartesian.h"
#include "tree.h"

class Window{
    private:
        int width;
        int height;

    public:

    Window(int argc, char ** argv, const int width, const int height);

    void draw_figure(Graph graph, bool circle);
    void main_loop();
    void clear();

    void draw_text(char * string, int x, int y);
    void draw_large_text(char * string, int x, int y);

    void draw_figure(Cartesian cartesian);

    void draw_function(Cartesian cartesian, std::vector<tPoint> coords);
    void draw_line(Cartesian cartesian, double x0, double y0, double x1, double y1);
    void draw_line(tPoint origin, tPoint destination);

    void draw_circle(tPoint center, float radius, float n_segments = 30);
    void draw_vertice(tPoint center, char * label, int radius, int n_segments = 30);

    void draw_tree(Node * root, tPoint coords, int radius, int n_segments = 30);
};




#endif
