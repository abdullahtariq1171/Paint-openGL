#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"


class Triangle :public Polygon
{
public:
	Triangle();
	Triangle::Triangle(Point *ptr);
	Triangle::Triangle(Point & p1, Point  & p2, Point & p3);
	Triangle(Triangle & );
	
	bool Triangle::Cantain(const Point & test);

	Point Triangle::GetP1();
	Point Triangle::GetP2();
	Point Triangle::GetP3();

	void Triangle::Draw();
	bool Triangle::IsExistInside();
	~Triangle();
};

#endif