#include "Polygon.h"

Polygon::Polygon():IsFilled(false){}
Polygon::Polygon(const int  & _n):IsFilled(false), Shape(_n){}
Polygon::Polygon(const int  & _n,  Point  *_ptr):Shape(_n,_ptr){}
void Polygon::SetFilledColor(const Color_RGB& _NewColor)
{
	this->FillingColor.SetColor(_NewColor);
}
void Polygon::SetFilledColor(const double & r, const double & g, const double & b)
{
	FillingColor.SetColor(r , g, b);
}
void Polygon::FilledStatus(const bool & _s)
{
	IsFilled = _s;
}
bool Polygon::Cantains(const Point & test)
{
	int i, j = 0;
	bool res = false;
	for (i = 0, j = NoOfPoints - 1; i < NoOfPoints; j = i++)
	{
		if (((PointsList[i].GetY()>test.GetY()) != (PointsList[j].GetY()>test.GetY())) && (test.GetX() < (PointsList[j].GetX() - PointsList[i].GetX()) * (test.GetY() - PointsList[i].GetY()) / (PointsList[j].GetY() - PointsList[i].GetY()) + PointsList[i].GetX()))
		{
			res = !res;
		}
	}
	return res;
}
void Polygon::Fill(Color_RGB color)
{
	this->FillingColor = color;
	IsFilled = true;
}
void Polygon::Draw()
{
	if (IsFilled == true)
	{
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glBegin(GL_LINE_LOOP);
		for (int i = 0; i < NoOfPoints; i++)
		{
			glVertex2i(PointsList[i].GetX(), PointsList[i].GetY());
		}
		glEnd();
		
		glColor3f(FillingColor.GetR_value(), FillingColor.GetG_value(), FillingColor.GetB_value());
		glPolygonMode(GL_FRONT, GL_FILL);
		glBegin(GL_POLYGON);
		for (int i = 0; i < NoOfPoints; i++)
		{
			glVertex2i(PointsList[i].GetX(), PointsList[i].GetY());
		}
		glEnd();
	}
	else
	{
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glBegin(GL_LINE_LOOP);
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		for (int i = 0; i < NoOfPoints; i++)
		{
			glVertex2i(PointsList[i].GetX(), PointsList[i].GetY());
		}
		glEnd();
	}
}
Polygon::~Polygon(){}
