#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <cstring>
#include <stdio.h>
#include "optgl.h"
#include <iostream>

#define WINDOW_DEFAULT_BORDER_SIZE 50

class Graph{
    private:

    std::vector<tPoint> vertices;

    double window_width;
    double window_height;

    double greatest_x_value;
    double greatest_y_value;
    

    void set_greatest_x();
    void set_greatest_y();

    public:

    Graph(double window_width, double window_height, std::vector<tPoint> vertices);

    void draw(std::vector<int>s);


    
};


#endif 