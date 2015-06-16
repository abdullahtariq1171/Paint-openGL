#ifndef DRAWING_AREA
#define DRAWING_AREA

#include <iostream>
using namespace std;
#include <fstream>
#include "Circle.h"
#include <vector>
#include "Line.h"
#include "Point.h" 
#include "Polygon.h"
#include "Text.h"
#include "Color_RGB.h"
#include "Rectangle.h"
#include "Curve.h"
#include "conio.h"
#include <stdlib.h>


class DrawingArea
{
	vector <Shape*> ShapeVec;

	/*int NoOfShapes;
	int Capacity;
	Shape **ShapePtr;*/

	void DrawingArea::PrintCurrentCursorCoordinate(const Point &);
	int DrawingArea::DetermineShapeType(const int index);
	void DrawingArea::LoadPointsFromFile(int NoOfPoints, ifstream & Input, Point *List , Color_RGB &);
public:
	DrawingArea();
	void DrawingArea::add(const int & ShapeIndicator, Point *PointShapePtr, const int & PointsForShape, Color_RGB ShapeColor);
	void DrawingArea::Deleting(const Point & Click);
	void DrawingArea::PrintDrawingArea(const Point & cursor);
	void DrawingArea::Filling(const Point & Click,  Color_RGB &);
	void DrawingArea::GetNewDocument(){ ShapeVec.clear(); }
	void DrawingArea::SaveDocument();

	void DrawingArea::LoadDocument();
	

	~DrawingArea();
};

#endif