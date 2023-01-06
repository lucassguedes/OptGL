#include "../include/optgl.h"

Window::Window(int argc, char ** argv, const int width, const int height)
{
    this->width = width;
    this->height = height;
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(this->width, this->height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("ILS Plotting");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0f, (double)this->width, 0.0f, (double)this->height, 0.0f, 1.0f);


    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}

void Window::draw_figure(Graph graph)
{
    tPoint coord1, coord2;
    char aux[80];
    /*Limpando o color buffer*/
    glClear(GL_COLOR_BUFFER_BIT);

    std::vector<int> s = graph.get_sequence();

    /*Determinando largura da linha*/
    std::vector<tPoint> vertices = graph.get_vertices();

    int greatest_x_value, greatest_y_value;
    
    greatest_x_value = graph.get_greatestx();
    greatest_y_value = graph.get_greatesty();

    glLineWidth(1.5);
    for(int i = 0; i < s.size()-1; i++){

        coord1 = vertices[s[i]-1];
        coord2 = vertices[s[i+1]-1];

        double x0,y0,x1,y1;    
        double factorX = (this->width - 2*WINDOW_DEFAULT_BORDER_SIZE)/(double)greatest_x_value;
        double factorY = (this->height - 2*WINDOW_DEFAULT_BORDER_SIZE)/(double)greatest_y_value;

        x0 = factorX * coord1.x + WINDOW_DEFAULT_BORDER_SIZE;
        y0 = factorY * coord1.y + WINDOW_DEFAULT_BORDER_SIZE;
        x1 = factorX * coord2.x + WINDOW_DEFAULT_BORDER_SIZE;
        y1 = factorY * coord2.y + WINDOW_DEFAULT_BORDER_SIZE;

        /*Definindo a cor para vermelho*/
        glColor3f(1.0, 0.0, 0.0);
        /*Desenhando número dos vértices, nas coordenadas devidas*/
        sprintf(aux, "%d", s[i]); /*Ponto inicial da linha*/
       this->draw_text(aux,x0,y0);
        sprintf(aux, "%d", s[i+1]); /*Ponto final da linha*/
       this->draw_text(aux,x1,y1);
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

void Window::draw_text(char * string, int x, int y)
{
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();

    glPushMatrix();
    // Posição no universo onde o texto será colocado          
    glRasterPos2f(x,y); 
    // Exibe caracter a caracter
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,*string++); 
    glPopMatrix();
}

void Window::draw_large_text(char * string, int x, int y)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    // Posição no universo onde o texto será colocado          
    glRasterPos2f(x,y); 
    // Exibe caracter a caracter
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*string++); 
    glPopMatrix();
}


void Window::clear()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void Window::main_loop()
{
    glutMainLoop();
}
