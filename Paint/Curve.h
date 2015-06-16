#ifndef CURVE_H
#define CURVE_H
#include "OpenShape.h"

class Curve:public OpenShape
{



public:
	Curve::Curve();
	Curve::Curve(const int & );
	Curve::Curve(const int & _n, Point *_Pointer);
	
	void Curve::Draw();

	bool Curve::Cantains(const Point & test);
	

	~Curve();
};

#endif