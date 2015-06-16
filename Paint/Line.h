#ifndef LINE_H
#define LINE_H
#include "Point.h"

#include "OpenShape.h"
#include "Shape.h"


class Line:public OpenShape
{


	bool Line::CheckInLimits(const Point & P);

public:
	Line(void);
	Line::Line(const double  & A1,const double & A2,const double & B1,const double & B2);
	Line::Line(Point & Starting,  Point & Ending);
	Line::Line(Line & Sample);

	Point Line::GetP1(void);
	Point Line::GetP2(void);


	bool Line::Cantains(const Point & a);


	void Line::Draw(void);
	~Line(void);
};


#endif