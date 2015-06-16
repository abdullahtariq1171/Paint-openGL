#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"

class Rectangle : public Polygon
{
public:
	Rectangle();
	Rectangle::Rectangle(Point _p1, Point _p2);
	Rectangle::Rectangle(Rectangle &);
	Rectangle::Rectangle(int P1x, int P1y, int P2x, int P2y);

	//SETTER
	void Rectangle::SetP1(Point P);
	void Rectangle::SetP2(Point P);

	void Rectangle::SetP1x(int);
	void Rectangle::SetP1y(int);
	void Rectangle::SetP2x(int);
	void Rectangle::SetP2y(int);
	//GETTERS
	Point Rectangle::GetP1();
	Point Rectangle::GetP2();
	
	void Rectangle::SpecialDraw();

	bool Rectangle::Cantains(const Point & P);


	void Rectangle::Draw();
	~Rectangle();
};

#endif
