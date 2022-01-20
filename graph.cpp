#include "graph.h"
#include "optgl.h"

Graph::Graph(double window_width, double window_height, std::vector<tPoint> vertices){
    this->window_width = window_width;
    this->window_height = window_height;

    this->vertices = vertices;

    this->set_greatest_x();
    this->set_greatest_y();
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

void Graph::draw(std::vector<int>s){
    tPoint coord1, coord2;
    char aux[80];
    /*Limpando o color buffer*/
    glClear(GL_COLOR_BUFFER_BIT);
    /*Determinando largura da linha*/
    glLineWidth(1.5);
    for(int i = 0; i < s.size()-1; i++){

        coord1 = this->vertices[s[i]-1];
        coord2 = this->vertices[s[i+1]-1];

        double x0,y0,x1,y1;    
        double factorX = (this->window_width - 2*WINDOW_DEFAULT_BORDER_SIZE)/this->greatest_x_value;
        double factorY = (this->window_height - 2*WINDOW_DEFAULT_BORDER_SIZE)/this->greatest_y_value;

        x0 = factorX * coord1.x + WINDOW_DEFAULT_BORDER_SIZE;
        y0 = factorY * coord1.y + WINDOW_DEFAULT_BORDER_SIZE;
        x1 = factorX * coord2.x + WINDOW_DEFAULT_BORDER_SIZE;
        y1 = factorY * coord2.y + WINDOW_DEFAULT_BORDER_SIZE;

        /*Definindo a cor para vermelho*/
        glColor3f(1.0, 0.0, 0.0);
        /*Desenhando número dos vértices, nas coordenadas devidas*/
        sprintf(aux, "%d", s[i]); /*Ponto inicial da linha*/
        optGLDrawText(aux,x0,y0);
        sprintf(aux, "%d", s[i+1]); /*Ponto final da linha*/
        optGLDrawText(aux,x1,y1);
        /*Definindo a cor para verde*/
        glColor3f(0.0, 0.0, 0.0);
        /*Desenhando linha que conecta os vértices*/
        glBegin(GL_LINES);
            glVertex2f(x0, y0);
            glVertex2f(x1, y1); 
        glEnd();                                                                                                                              
        
    }
    glFlush();
}