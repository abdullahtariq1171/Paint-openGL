#include <iostream>
using namespace std;
#include "Line.h"
#include "Point.h"


Line::Line(void):OpenShape(2){}
Line::Line(const double  & A1, const double & A2, const double & B1, const double & B2) : OpenShape(2)
{
	PointsList[0].SetPoint(A1 , A2);
	PointsList[1].SetPoint(B1, B2);
}
Line::Line(Point & Starting, Point & Ending) : OpenShape(2)
{
	this->PointsList[0].SetPoint(Starting);
	this->PointsList[1].SetPoint(Ending);
}
Line::Line(Line & Sample) : OpenShape(2)
{
	PointsList[0].SetPoint(Sample.PointsList[0].GetPoint());
	PointsList[1].SetPoint(Sample.PointsList[1].GetPoint());
}
Point Line::GetP1(void){ return PointsList[0]; }
Point Line::GetP2(void){ return this->PointsList[1];}
void Line::Draw(void)
{
	glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
	glBegin(GL_LINES);
		glVertex2i(this->PointsList[0].GetX(), this->PointsList[0].GetY());
		glVertex2i(this->PointsList[1].GetX(), this->PointsList[1].GetY());
	glEnd();

}
Line::~Line(void){}

bool Line::CheckInLimits(const Point & P)
{
	if ((P.GetX() >= PointsList[0].GetX() && P.GetX() <= PointsList[1].GetX()) || (P.GetX() <= PointsList[0].GetX() && P.GetX() >= PointsList[1].GetX()))
	{
		if ((P.GetY() <= PointsList[0].GetY() && P.GetY() >= PointsList[1].GetY()) || (P.GetY() >= PointsList[0].GetY() && P.GetY() <= PointsList[1].GetY()))
		{
			return true;
		}
	}
	return false;
}

bool Line::Cantains(const Point & test)
{
	bool Limit = false;
	Limit = CheckInLimits(test);
	if (!Limit){
		return false;
	}
	
	double dx = PointsList[1].GetX() - PointsList[0].GetX();
	double dy = PointsList[1].GetY() - PointsList[0].GetY();
	double slope = dy / dx;
	int tolerance = 3;
	if ((test.GetY() - PointsList[1].GetY()) == slope*(test.GetX() - PointsList[1].GetX()))
		return true;
	else if (((test.GetY() - PointsList[1].GetY()) > slope*(test.GetX() - PointsList[1].GetX())) && ((test.GetY() - PointsList[1].GetY()) <tolerance + (slope*(test.GetX() - PointsList[1].GetX()))))
		return true;
	else if (((test.GetY() - PointsList[1].GetY()) < slope*(test.GetX() - PointsList[1].GetX())) && ((test.GetY() - PointsList[1].GetY())  > -tolerance +(slope*(test.GetX() - PointsList[1].GetX()) )))
		return true;
	else return false;
}
