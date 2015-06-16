#include <iostream>
using namespace std;
#include "Circle.h"
#include <math.h>


Circle::Circle(void):Radius(0.0),Shape(1){}
Circle::Circle(const double & _x, const  double  & _y, const double & Rad) : Radius(Rad), Shape(1)
{
	Shape::PointsList[0].SetX(_x);
	Shape::PointsList[0].SetY(_y); 
}
Circle::Circle(Point & Cent,const double & Rad) : Radius(Rad), Shape(1)
{
	this->PointsList[0].SetPoint(Cent);
}
Circle::Circle(const Point & Cent, const Point & Point_On_Circle_Circumference) : Shape(1), Radius(Cent.CalculateDistance(Point_On_Circle_Circumference))
{
	Shape::PointsList[0].SetPoint(Cent);
}
Circle::Circle(Circle & Source) : Radius(Source.GetRadius()), Shape(1){}
void Circle::Draw()
{
	if (!IsFilled)
	{

		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glBegin(GL_LINE_LOOP);
		int Segments = 1000;
		for (GLint i = 0; i < Segments; i++)
		{
			float theta = 2.0 * 3.1415926 * float(i) / float(Segments);//get the current angle 
			float x = this->Radius * cosf(theta);//calculate the x component 
			float y = this->Radius * sinf(theta);//calculate the y component
			glVertex2f(x + Shape::PointsList[0].GetX(), y + Shape::PointsList[0].GetY());//output vertex 
		}
		glEnd();
		glClear(0);
	}
	else
	{
		glColor3f(FillingColor.GetR_value(), FillingColor.GetG_value(), FillingColor.GetB_value());
		glBegin(GL_TRIANGLE_FAN);
		int Segments = 1000;
		for (GLint i = 0; i < Segments; i++)
		{
			float theta = 2.0 * 3.1415926 * float(i) / float(Segments);//get the current angle 
			float x = this->Radius * cosf(theta);//calculate the x component 
			float y = this->Radius * sinf(theta);//calculate the y component
			glVertex2f(x + Shape::PointsList[0].GetX(), y + Shape::PointsList[0].GetY());//output vertex 
		}
		glEnd();
		glClear(0);



		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glBegin(GL_LINE_LOOP);
		for (GLint i = 0; i < Segments; i++)
		{
			float theta = 2.0 * 3.1415926 * float(i) / float(Segments);//get the current angle 
			float x = this->Radius * cosf(theta);//calculate the x component 
			float y = this->Radius * sinf(theta);//calculate the y component
			glVertex2f(x + Shape::PointsList[0].GetX(), y + Shape::PointsList[0].GetY());//output vertex 
		}
		glEnd();
		glClear(0);
	}
}
bool Circle::Cantains(const Point & _p)
{
	if (PointsList[0].CalculateDistance(_p) > Radius){ return false; }
	else return true;
}
void Circle::FilledStatus(const bool & _s){ IsFilled = _s;}
double Circle::GetRadius()const{return this->Radius;}
Point Circle::GetCenter()const{ return this->Shape::PointsList[0];}
void Circle::SetRadius(const double & Rad){ this->Radius = Rad;}
void Circle::SetRadius(const int & Rad){ this->Radius = Rad;}
void Circle::SetCenter(Point & C)
{
	this->Shape::PointsList[0].SetX(C.GetX());
	this->Shape::PointsList[0].SetY(C.GetY());
}
void Circle::Fill(Color_RGB color)
{
	this->FillingColor = color;
	IsFilled = true;
}
Circle::~Circle(void){}
