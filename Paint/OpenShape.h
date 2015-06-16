#ifndef OPEHSHAPE_H
#define OPEHSHAPE_H

#include "Shape.h"
class OpenShape :
	public Shape
{
public:
	OpenShape::OpenShape();
	OpenShape::OpenShape(const int &);
	OpenShape::OpenShape(const int & _n, Point  *ptr);
	void OpenShape::Draw() = 0;

	
	virtual void OpenShape::Fill(Color_RGB color);
	virtual bool OpenShape::Cantains(const Point & a)=0;
	OpenShape::~OpenShape(){};
};

#endif 