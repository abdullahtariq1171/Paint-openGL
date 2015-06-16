#include <iostream>
using namespace std;
#include "Point.h"
#include <glut.h>


#define Point_Color 5

//CONSTRUCTORS
Point::Point(void):x(0),y(0){}
Point::Point(const double _x,const double _y):x(_x),y(_y){}
Point::Point(const Point & Source) 
	:x(Source.GetX()),y(Source.GetY()){}

//GETTERS
double Point::GetX(void)const {return this->x;}
double Point::GetY(void)const {return this->y;}
Point Point::GetPoint(void)const{return (*this);}
//SETTERS
void Point::SetX(const double & _x){
	this->x = _x; 
}
void Point::SetY(const double & _y){this->y=_y;}

void Point::SetPoint(const Point & _p)
{
	this->x = _p.GetX();
	this->y = _p.GetY();

}
void Point::SetPoint(const double & _x, const double &_y)
{
	this->x = _x;
	this->y = _y;
}


double Point::CalculateDistance(const Point & _p2)const
{
	return sqrt(  ((_p2.GetX() - x)*(_p2.GetX() - x)) + ((_p2.GetY() - y)*(_p2.GetY() - y))  );
}

void Point::Draw()
{

	//COLOR NEED TO BE SET YET
	glBegin(GL_POINTS);
		glVertex2i(this->x, this->y);
	glEnd();
}

Point Point::operator=(const Point & RHS)
{
	this->SetPoint(RHS.GetPoint());
	return  (*this);
}



//DESTRUCTOR
Point::~Point(void){}