#include "OpenShape.h"


OpenShape::OpenShape()
{
}

OpenShape::OpenShape(const int & _n) :Shape(_n)
{
}


void OpenShape::Fill(Color_RGB color)
{
	this->Shape_Color = color;
}


OpenShape::OpenShape(const int & _n, Point  *ptr) : Shape(_n, ptr){}

