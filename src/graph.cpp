#include "../include/graph.h"

Graph::Graph(std::vector<tPoint> vertices){
    this->vertices = vertices;

    this->set_greatest_x();
    this->set_greatest_y();
}

int Graph::get_greatestx()
{
    return this->greatest_x_value;
}
int Graph::get_greatesty()
{
    return this->greatest_y_value;
}

void Graph::set_greatest_x(){
    this->greatest_x_value = this->vertices[0].x;
    for(size_t i = 1; i < this->vertices.size(); i++)
    {
        if(this->vertices[i].x >= this->greatest_x_value)
            this->greatest_x_value = this->vertices[i].x;
    }
}

void Graph::set_greatest_y(){
    this->greatest_y_value = this->vertices[0].y;
    for(size_t i = 1; i < this->vertices.size(); i++)
    {
        if(this->vertices[i].y >= this->greatest_y_value)
            this->greatest_y_value = this->vertices[i].y;
    }
}


std::vector<std::pair<int, int> > Graph::get_edges(){
	return this->edges;
}

void Graph::set_edges(std::vector<std::pair<int, int> > edges){
	this->edges = edges;
}

std::vector<tPoint> Graph::get_vertices()
{
    return this->vertices;
}
