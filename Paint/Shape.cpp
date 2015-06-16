#include <iostream>
using namespace std;
#include "Shape.h"

Shape::Shape() :NoOfPoints(0), PointsList(nullptr){};
Shape::Shape(const int & no_of_points) :NoOfPoints(no_of_points), PointsList(new Point[no_of_points]){};
Shape::Shape(const int & no_of_points, const Color_RGB & _color) :NoOfPoints(no_of_points), PointsList(new Point[no_of_points]), Shape_Color(_color){}
Shape::Shape(const int & no_of_points, const Point *_ptr)
{
	NoOfPoints = no_of_points;
	PointsList = new Point[NoOfPoints];
	for (int i = 0; i < NoOfPoints; i++)
		PointsList[i] = _ptr[i];
}
Point Shape::GetPoint(const int index)const
{
	return PointsList[index];
}
void Shape::SetShapeColor(const Color_RGB & _NewColor)
{
	this->Shape_Color.SetColor(_NewColor);
}
void Shape::SetShapeColor(const double & r, const double & g, const double & b)
{
	this->Shape_Color.SetColor(r, g, b);
}
Shape::~Shape()
{
	if (PointsList != nullptr)
	{
		delete[]PointsList;
		PointsList = nullptr;
	}
}
