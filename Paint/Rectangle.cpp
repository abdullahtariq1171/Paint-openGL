#include <iostream>
using namespace std;
#include "Rectangle.h"

//CONSTRUCTORS
Rectangle::Rectangle():Polygon(2){}
Rectangle::Rectangle(Point _p1, Point _p2): Polygon(2)
{
	this->FilledStatus(false);
	PointsList[0].SetPoint(_p1);
	PointsList[1].SetPoint(_p2);
}
Rectangle::Rectangle(Rectangle & R) : Polygon(2)
{
	PointsList[0].SetPoint(R.GetP1());
	PointsList[1].SetPoint(R.GetP2());
}
Rectangle::Rectangle(int P1x, int P1y, int P2x, int P2y):Polygon(2)
{
	PointsList[0].SetPoint(P1x, P1y);
	PointsList[1].SetPoint(P2x, P2y);
}
//SETTERS
void Rectangle::SetP1(Point P)
{
	this->PointsList[0].SetPoint(P.GetPoint());
}
void Rectangle::SetP2(Point P)
{
	this->PointsList[1].SetPoint(P.GetPoint());
}
void Rectangle::SetP1x(int a){ this->PointsList[0].SetX(a); }
void Rectangle::SetP1y(int a){ this->PointsList[0].SetY(a); }
void Rectangle::SetP2x(int a){ this->PointsList[1].SetX(a); }
void Rectangle::SetP2y(int a){ this->PointsList[1].SetY(a); }
//GETTERS
Point Rectangle::GetP1(){ return PointsList[0];}
Point Rectangle::GetP2(){ return PointsList[1];}
//CHECK WHETEHR A POINT IS INSIDE OR NOT
bool Rectangle::Cantains(const Point & P)
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
//DEAWING FUNCTION
void Rectangle::Draw()
{

	if (IsFilled==true)
	{
		glColor3f(FillingColor.GetR_value(), FillingColor.GetG_value(), FillingColor.GetB_value());
		glPolygonMode(GL_FRONT, GL_FILL);
		glBegin(GL_POLYGON);
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY());
		glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY());
		glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
		glEnd();

		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glBegin(GL_LINE_LOOP);
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY());
		glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY());
		glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
		glEnd();


		
	}
	else
	{
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glBegin(GL_LINE_LOOP);
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
			glVertex2i(PointsList[0].GetX(), PointsList[0].GetY());
			glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY());
			glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
			glVertex2i(PointsList[0].GetX(), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
		glEnd();
	}
}
void Rectangle::SpecialDraw()
{

	if (IsFilled == true)
	{
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glBegin(GL_LINE_LOOP);
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY());
		glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY());
		glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
		glEnd();

		glColor3f(FillingColor.GetR_value(), FillingColor.GetG_value(), FillingColor.GetB_value());
		glPolygonMode(GL_FRONT, GL_FILL);
		glBegin(GL_POLYGON);
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY());
		glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY());
		glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
		glEnd();

	}
	else
	{
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glBegin(GL_LINE_LOOP);
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY());
		glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY());
		glVertex2i(PointsList[0].GetX() + (PointsList[1].GetX() - PointsList[0].GetX()), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY() + (PointsList[1].GetY() - PointsList[0].GetY()));
		glEnd();
	}
}
//DESTRUCTOR
Rectangle::~Rectangle(){}