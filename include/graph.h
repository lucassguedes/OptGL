#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <vector>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include "point.h"

#define WINDOW_DEFAULT_BORDER_SIZE 50

class Graph{
    private:

    std::vector<int> sequence;
    std::vector<tPoint> vertices;


    int greatest_x_value;
    int greatest_y_value;
    

    void set_greatest_x();
    void set_greatest_y();


    public:
    
    std::vector<int> get_sequence();
    std::vector<tPoint> get_vertices();

    int get_greatestx();
    int get_greatesty();    
    
    void set_sequence(std::vector<int> sequence);

    Graph(std::vector<tPoint> vertices);
};


#endif 