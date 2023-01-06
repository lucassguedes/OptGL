#ifndef _POINT_H_
#define _POINT_H_

class tPoint{
    public: 
    int node;
    double x;
    double y;

    tPoint(){}

    tPoint(double x, double y){
        this->x = x;
        this->y = y;
    }
};

#endif 