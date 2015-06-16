#ifndef SHAPE_H
#define SHAPE_H
#include <vector>
#include <fstream>
#include "Point.h"
#include "Color_RGB.h"
#include <stdlib.h>
#include <glut.h>



class Shape
{
protected:
	int NoOfPoints;
	Color_RGB Shape_Color;
	Point *PointsList;
public:
	Shape::Shape();
	Shape::Shape(const int & no_of_points);
	Shape::Shape(const int & no_of_points , const Point *_ptr);
	Shape::Shape(const int & no_of_points, const Color_RGB &);
	Shape::Shape(const  Shape &);
	void Shape::SetShapeColor(const Color_RGB &);
	void Shape::SetShapeColor(const double & r, const double & g, const double & b);
	
	Color_RGB Shape::GetShapeColor(){ return this->Shape_Color; }

	Shape& Shape::operator=(Shape const & RHS);
	virtual void Shape::Fill(Color_RGB color) = 0;
	virtual void Shape::Draw() = 0;
	virtual bool Shape::Cantains(const Point & a)=0;
	int Shape::GetNoOfPoints(){ return NoOfPoints; }
 
	Point Shape::GetPoint(const int index)const;

	virtual ~Shape();
};

#endif