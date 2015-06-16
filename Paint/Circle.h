#ifndef CIRCLE_H
#define CIRCLE_H
#include "Color_RGB.h"

#include "Shape.h"

class Circle :public Shape
{
	double Radius;
	bool IsFilled;
	Color_RGB FillingColor;
public:

	Circle(void);
	Circle::Circle(const double & _x,const  double & _y,const  double & Rad);
	Circle::Circle(const Point & Cent, const Point & Point_On_Circle_Circumference);
	Circle::Circle(Point&,const double &);
	Circle::Circle(Circle&Source);

	virtual void Circle::Draw();

	bool Circle::Cantains(const Point & );

	bool Circle::GetFilledStatus(){ return IsFilled; }
	
	Color_RGB Circle::GetFilledColor(){ return FillingColor; }


	void Circle::FilledStatus(const bool & );
	void Circle::Fill(Color_RGB color);

	double Circle::GetRadius()const;
	Point Circle::GetCenter()const;

	void Circle::SetRadius(const int &);
	void Circle::SetRadius(const double & );
	void Circle::SetCenter(Point & );

	~Circle(void);
};

#endif