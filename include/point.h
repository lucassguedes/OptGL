#ifndef _POINT_H_
#define _POINT_H_

#include <cstdio>
#include <string>

class tPoint{
    public: 
    char content[100];
	bool visible;
    double x;
    double y;

    tPoint(){}

    tPoint(double x, double y){
        this->x = x;
        this->y = y;
		this->visible = true;
    }

	tPoint(std::string content, double x, double y)
	{
		sprintf(this->content, "%s", content.c_str());
		this->x = x;
		this->y = y;
		this->visible = true;
	}

	void set_content(std::string content){
		sprintf(this->content, "%s", content.c_str());
	}

	void set_visible(bool visible){
		this->visible = visible;
	}
};

#endif 
