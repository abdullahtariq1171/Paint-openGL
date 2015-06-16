#include <iostream>
using namespace std;
#include "Curve.h"

Curve::Curve(){}


Curve::Curve(const int & _n, Point *_Pointer) :OpenShape(_n, _Pointer){}

void Curve::Draw()
{
	glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < NoOfPoints; i++)
	{
		glVertex2i(PointsList[i].GetX(), PointsList[i].GetY());
	}
	glEnd();

}



bool Curve::Cantains(const Point & test)
{
	for (int i = 0; i < this->NoOfPoints-1; i++)
	{

		double dx = PointsList[i+1].GetX() - PointsList[i].GetX();
		double dy = PointsList[i+1].GetY() - PointsList[i].GetY();
		double slope = dy / dx;
		// y = mx + c
		// intercept c = y - mx
		int tolerance = 3;
		if ((test.GetY() - PointsList[i+1].GetY()) == slope*(test.GetX() - PointsList[i+1].GetX()))
			return true;
		else if (((test.GetY() - PointsList[i+1].GetY()) > slope*(test.GetX() - PointsList[i+1].GetX())) && ((test.GetY() - PointsList[i+1].GetY()) < tolerance + (slope*(test.GetX() - PointsList[i+1].GetX()))))
			return true;
		else if (((test.GetY() - PointsList[i+1].GetY()) < slope*(test.GetX() - PointsList[i+1].GetX())) && ((test.GetY() - PointsList[i+1].GetY())  > -tolerance + (slope*(test.GetX() - PointsList[i+1].GetX()))))
			return true;
	}
	return false;
}

Curve::~Curve()
{
}
