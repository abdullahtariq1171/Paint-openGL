#ifndef POLYGONE_H
#define POLYGONE_H
#include "Shape.h"

class Polygon :public Shape
{
protected:
	bool IsFilled;
	Color_RGB FillingColor;

public:
	Polygon::Polygon();
	Polygon::Polygon(const int  & _n);
	Polygon::Polygon(const int  & _n ,Point  *_ptr);
	
	void Polygon::FilledStatus(const bool &);
	
	bool Polygon::IsPolygonFilled(){ return IsFilled;}
	bool Polygon::Cantains(const Point & test);

	Color_RGB Polygon::GetFilledColor(){ return FillingColor; }

	 void Polygon::Fill(Color_RGB color);

	 void Polygon::Draw();

	
	void Polygon::SetFilledColor(const Color_RGB&);
	void Polygon::SetFilledColor(const double & r, const double & g, const double & b);


	 ~Polygon();
};


#endif