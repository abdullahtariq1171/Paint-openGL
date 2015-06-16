#include "Triangle.h"

Triangle::Triangle():Polygon(3){}
Triangle::Triangle(Point *ptr):Polygon(3,ptr){}
Triangle::Triangle(Point & p1, Point & p2, Point & p3):Polygon(3)
{
	PointsList[0].SetPoint(p1);
	PointsList[1].SetPoint(p2);
	PointsList[2].SetPoint(p3);
}
Triangle::Triangle(Triangle & T)
{
	glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
	PointsList[0] = T.GetP1();
	PointsList[1] = T.GetP2();
	PointsList[2] = T.GetP3();
}

Point Triangle::GetP1(){ return PointsList[0];}
Point Triangle::GetP2(){ return PointsList[1];}
Point  Triangle::GetP3(){ return PointsList[2];}

bool Triangle::Cantain(const Point & test)
{
	int i, j = 0;
	bool res = false;
	for (i = 0, j = NoOfPoints - 1; i < NoOfPoints; j = i++)
	{
		if (((PointsList[i].GetY()>test.GetY()) != (PointsList[j].GetY()>test.GetY())) && (test.GetX() < (PointsList[j].GetX() - PointsList[i].GetX()) * (test.GetY() - PointsList[i].GetY()) / (PointsList[j].GetY() - PointsList[i].GetY()) + PointsList[i].GetX()))
		{
			res = !res;
		}
	}
	return res;
}
void Triangle::Draw()
{
	if (IsFilled == true)
	{
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glBegin(GL_LINE_LOOP);
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY());			
		glVertex2i(PointsList[1].GetX(), PointsList[1].GetY());
		glVertex2i(PointsList[2].GetX(), PointsList[2].GetY());
		glEnd();


		glColor3f(FillingColor.GetR_value(), FillingColor.GetG_value(), FillingColor.GetB_value());
		glPolygonMode(GL_FRONT, GL_FILL);
		glBegin(GL_POLYGON);
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY());			
		glVertex2i(PointsList[1].GetX(), PointsList[1].GetY());
		glVertex2i(PointsList[2].GetX(), PointsList[2].GetY());
		glEnd();
	}
	else
	{
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glBegin(GL_LINE_LOOP);
		glColor3f(Shape_Color.GetR_value(), Shape_Color.GetG_value(), Shape_Color.GetB_value());
		glVertex2i(PointsList[0].GetX(), PointsList[0].GetY());			// specify each vertex of square 
		glVertex2i(PointsList[1].GetX(), PointsList[1].GetY());
		glVertex2i(PointsList[2].GetX(), PointsList[2].GetY());
		glEnd();
	}

}

Triangle::~Triangle(){}

