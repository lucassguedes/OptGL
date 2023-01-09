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

void Window::draw_figure(Cartesian cartesian)
{
    glLineWidth(1.5);
    glColor3f(0.0, 0.0, 0.0);

    double xStep, yStep, x_value_increment, y_value_increment;


    int x_max = cartesian.x_upperbound / UPPER_BOUND_FACTOR;



    xStep = (X_AXIS_SIZE_IN_PIXELS / 8);
    yStep = (Y_AXIS_SIZE_IN_PIXELS / 8);

    x_value_increment = (1.0 / 8) * x_max;
    y_value_increment = (1.0 / 8) * cartesian.y_upperbound;

    // Drawing the x axis
    glBegin(GL_LINES);
    glVertex2f(cartesian.origin.x, cartesian.origin.y);
    glVertex2f(cartesian.origin.x + X_AXIS_SIZE_IN_PIXELS, cartesian.origin.y);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(cartesian.origin.x + X_AXIS_SIZE_IN_PIXELS, cartesian.origin.y - AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->height);
    glVertex2f(cartesian.origin.x + X_AXIS_SIZE_IN_PIXELS, cartesian.origin.y + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->height);
    glVertex2f(cartesian.origin.x + X_AXIS_SIZE_IN_PIXELS + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->width, cartesian.origin.y);
    glEnd();

    // Drawing the y axis
    glBegin(GL_LINES);
    glVertex2f(cartesian.origin.x, cartesian.origin.y);
    glVertex2f(cartesian.origin.x, cartesian.origin.y + Y_AXIS_SIZE_IN_PIXELS);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(cartesian.origin.x - AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->height, cartesian.origin.y + Y_AXIS_SIZE_IN_PIXELS);
    glVertex2f(cartesian.origin.x + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->height, cartesian.origin.y + Y_AXIS_SIZE_IN_PIXELS);
    glVertex2f(cartesian.origin.x, cartesian.origin.y + Y_AXIS_SIZE_IN_PIXELS + AXIS_TRIANGLE_MAIN_SIDE_HALF_SIZE_FACTOR * this->width);
    glEnd();

    /*Drawing the x value indicators*/

    for (int i = cartesian.origin.x, j = 0; i < cartesian.origin.x + X_AXIS_SIZE_IN_PIXELS; i += xStep, j += x_value_increment)
    {
        glBegin(GL_LINES);
        glVertex2f(i, cartesian.origin.y - VALUE_INDICATOR_LINE_HALF_SIZE * this->height);
        glVertex2f(i, cartesian.origin.y + VALUE_INDICATOR_LINE_HALF_SIZE * this->height);
        glEnd();

        char coordX[200];

        sprintf(coordX, "%d", j);

        this->draw_text(coordX, i, cartesian.origin.y - 0.02 * this->height);
    }

    /*Drawing the y value indicators*/
    for (int i = cartesian.origin.y, j = 0; i < cartesian.origin.y + Y_AXIS_SIZE_IN_PIXELS; i += yStep, j += y_value_increment)
    {
        glBegin(GL_LINES);
        glVertex2f(cartesian.origin.x - VALUE_INDICATOR_LINE_HALF_SIZE * this->height, i);
        glVertex2f(cartesian.origin.x + VALUE_INDICATOR_LINE_HALF_SIZE * this->height, i);
        glEnd();

        char coordY[200];

        sprintf(coordY, "%d", j);

        this->draw_text(coordY, cartesian.origin.x - 0.045 * this->height, i);
    }

    /*Axis names*/
    char axisName[50];

    strcpy(axisName, cartesian.horizontal_axis_name.c_str());

    this->draw_large_text(axisName, cartesian.origin.x + X_AXIS_SIZE_IN_PIXELS / 2, cartesian.origin.y - 0.1 * this->height);

    strcpy(axisName, cartesian.vertical_axis_name.c_str());
    this->draw_large_text(axisName, cartesian.origin.x - 0.1 * this->height, cartesian.origin.y + Y_AXIS_SIZE_IN_PIXELS / 2);
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

void Window::draw_line(tPoint origin, tPoint destination)
{
    glColor3f(1.0, 0.0, 0);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(origin.x, origin.y);
    glVertex2f(destination.x, destination.y);
    glEnd();
    glFlush();
}

void Window::draw_line(Cartesian cartesian, double x0, double y0, double x1, double y1)
{
    double x0coord = cartesian.origin.x + (X_AXIS_SIZE_IN_PIXELS * x0) / (cartesian.x_upperbound / UPPER_BOUND_FACTOR);
    double y0coord = cartesian.origin.y + (Y_AXIS_SIZE_IN_PIXELS) * (y0 / (cartesian.y_upperbound));

    double x1coord = cartesian.origin.x + (X_AXIS_SIZE_IN_PIXELS * x1) / (cartesian.x_upperbound / UPPER_BOUND_FACTOR);
    double y1coord = cartesian.origin.y + (Y_AXIS_SIZE_IN_PIXELS) * (y1 / (cartesian.y_upperbound));

    if (x1coord <= cartesian.origin.x + X_AXIS_SIZE_IN_PIXELS && y1coord <= cartesian.origin.y + Y_AXIS_SIZE_IN_PIXELS)
    {

        if (y0coord > cartesian.origin.y + Y_AXIS_SIZE_IN_PIXELS)
            y0coord = cartesian.origin.y + Y_AXIS_SIZE_IN_PIXELS;

        glColor3f(cartesian.line_color_rgb[0], cartesian.line_color_rgb[1], cartesian.line_color_rgb[2]);
        glBegin(GL_LINES);
        glVertex2f(x0coord, y0coord);
        glVertex2f(x1coord, y1coord);
        glEnd();

        glFlush();
    }
}

void Window::draw_function(Cartesian cartesian, std::vector<tPoint> coords)
{
    double previous_x = coords[0].x;
    double previous_y = coords[0].y;

    for (size_t i = 1; i < coords.size(); i++)
    {
        this->draw_line(cartesian, previous_x, previous_y, coords[i].x, coords[i].y);
        previous_x = coords[i].x;
        previous_y = coords[i].y;
    }
}

void Window::draw_circle(tPoint center, float radius, float n_segments)
{

    tPoint current_point = center;
    tPoint previous_point = tPoint(radius, 0);
    tPoint new_point = tPoint(0,0);

    float step_angle = (2 * 3.1415926) / n_segments;

    glColor3f(0.75, 0.0, 0.0);
    for(int i = 0; i <= n_segments; i++)
    {
        new_point = tPoint(radius * cos(step_angle * i), radius * sin(step_angle * i));
        glBegin(GL_TRIANGLES);
        glVertex3f(center.x, center.y,0.0);
        glVertex3f(center.x + previous_point.x, center.y + previous_point.y,0.0);
        glVertex3f(center.x + new_point.x, center.y + new_point.y,0.0);
        glEnd();

        previous_point = new_point;
        glFlush(); 
    }

}

void Window::draw_vertice(tPoint center, char * label, int radius, int n_segments)
{
    this->draw_circle(center, radius, n_segments);
    glColor3f(0.0, 0.0, 0);
    if(radius <= 50)
    {
        this->draw_text(label, center.x, center.y);
    }else{
        this->draw_large_text(label, center.x, center.y);
    }
    glFlush();
}

void Window::draw_tree(Node * root, tPoint coords, int radius, int n_segments)
{

    tPoint childcoord = coords;
    std::vector<tPoint> children_coords;

    int n_child = root->n_descendants;
    n_child = n_child > 1 ? n_child - 1 : n_child;

    childcoord.y -= (4 * radius);
    childcoord.x -= (n_child * 2 * radius);

    for(int i = 0; i < root->children.size(); i++)
    {
        this->draw_line(coords, childcoord);
        children_coords.push_back(childcoord);
        childcoord.x += n_child * 2 * radius;
    }

    this->draw_vertice(coords, root->name, radius, n_segments);

    if(!root->children.size())
        return;

    for(int i = 0; i < root->children.size(); i++)
    {
        this->draw_vertice(children_coords[i], root->children[i]->name, radius, n_segments);
        this->draw_tree(root->children[i], children_coords[i], radius);
    }
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
