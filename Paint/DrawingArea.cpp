#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <string>
#include "DrawingArea.h"
#include "Circle.h"
#include "Line.h"
#include "Point.h" 
#include "Polygon.h"
#include "Text.h"
#include "Color_RGB.h"
#include "Text.h"
#include "Triangle.h"
#include "Rectangle.h"
#include <stdlib.h>
#include <glut.h>

void PrintString(char s[], int tx, int ty)
{
	#define FONT			GLUT_BITMAP_TIMES_ROMAN_24
	#define CHAR_H			18
	#define LINE_SEP		4

	glColor3f(0.0f, 0.0f, 0.0f);
	int x, y;
	x = tx;
	y = ty;
	int i = 0;
	int width;
	while (s[i] != '\0')
	{
		width = glutBitmapWidth(FONT, s[i]);
		if (s[i] == '\n') {
			x = tx;
			y += CHAR_H + LINE_SEP;
		}
		else
		{
			glRasterPos2i(x, y);
			glutBitmapCharacter(FONT, s[i]);
			x += width;
		}
		++i;
	}
}
DrawingArea::DrawingArea(){}
void DrawingArea::add(const int & ShapeIndicator , Point *PointShapePtr, const int & PointsForShape , Color_RGB ShapeColor)
{
	//if (this->Capacity == this->NoOfShapes)
	//{
	//	Shape **temp=ShapePtr;
	//	
	//	this->Capacity = this->Capacity * 2;
	//	
	//	this->ShapePtr = new Shape*[Capacity];
	//	for (int i = 0; i < this->NoOfShapes; i++)
	//		this->ShapePtr[i] = temp[i];

	//	cout << "Here;";
	//	for (int i = 0; i < NoOfShapes; i++)
	//	{
	//	//	delete temp[i];
	//	}
	//	cout << "df";
	//	//delete temp;
	//	//temp = nullptr;
	//	cout << "no";

	//	for (int i = 0; i < this->NoOfShapes; i++)
	//		temp[i]->Draw();

	//	cout << "done \n";
	//}

	int NoOf_Shapes = ShapeVec.size();
	if (ShapeIndicator==0)
	{
		
		ShapeVec.push_back(new Circle(PointShapePtr[0], PointShapePtr[1]));
		ShapeVec[NoOf_Shapes]->SetShapeColor(ShapeColor);

		/*this->ShapePtr[NoOfShapes] = new Circle(PointShapePtr[0], PointShapePtr[1]);
	
		(*ShapePtr[NoOfShapes]).SetShapeColor(ShapeColor);*/
	//	NoOfShapes++;
	}
	else 
	if (ShapeIndicator == 1)
	{
		ShapeVec.push_back(new Rectangle(PointShapePtr[0], PointShapePtr[1]));
		ShapeVec[NoOf_Shapes]->SetShapeColor(ShapeColor);

		/*this->ShapePtr[NoOfShapes] = new Rectangle(PointShapePtr[0], PointShapePtr[1]);
		(*ShapePtr[NoOfShapes]).SetShapeColor(ShapeColor);*/
//		NoOfShapes++;
	}
	else 
	if (ShapeIndicator == 2)
	{
		ShapeVec.push_back(new Line(PointShapePtr[0], PointShapePtr[1]));
		ShapeVec[NoOf_Shapes]->SetShapeColor(ShapeColor);
		//this->ShapePtr[NoOfShapes] = new Line(PointShapePtr[0], PointShapePtr[1]);
		//(*ShapePtr[NoOfShapes]).SetShapeColor(ShapeColor);
	//	NoOfShapes++;
	}
	else 
	if (ShapeIndicator == 3)
	{
		ShapeVec.push_back(new Triangle(PointShapePtr[0], PointShapePtr[1], PointShapePtr[2]));
		ShapeVec[NoOf_Shapes]->SetShapeColor(ShapeColor);
		//this->ShapePtr[NoOfShapes] = new Triangle(PointShapePtr[0], PointShapePtr[1], PointShapePtr[2]);
		//(*ShapePtr[NoOfShapes]).SetShapeColor(ShapeColor);
	//	NoOfShapes++;
	}
	else
	if (ShapeIndicator == 4)
	{
		ShapeVec.push_back(new Curve(PointsForShape, PointShapePtr));
		ShapeVec[NoOf_Shapes]->SetShapeColor(ShapeColor);
		/*new Triangle(PointShapePtr[0], PointShapePtr[1], PointShapePtr[2]);
		this->ShapePtr[NoOfShapes] = new Curve(PointsForShape, PointShapePtr);
		(*ShapePtr[NoOfShapes]).SetShapeColor(ShapeColor);*/
	//	NoOfShapes++;
	}
	else
	if (ShapeIndicator == 5)
	{
		ShapeVec.push_back(new Polygon(PointsForShape, PointShapePtr));
		ShapeVec[NoOf_Shapes]->SetShapeColor(ShapeColor);
		/*this->ShapePtr[NoOfShapes] = new Polygon(PointsForShape, PointShapePtr);
		(*ShapePtr[NoOfShapes]).SetShapeColor(ShapeColor);
		*/
		//NoOfShapes++;
	}
//	cout << "No Of Shapes Are:" << this->NoOfShapes << endl;
}
void DrawingArea::Filling(const Point & Click,  Color_RGB & color)
{
	bool Flag = false;
	for (int i = ShapeVec.size()-1 ; i >=0 && !Flag; i--)
	{
		Flag = ShapeVec[i]->Cantains(Click);
		if (Flag)
			ShapeVec[i]->Fill(color);
	}

}
void DrawingArea::Deleting(const Point & Click)
{
	for (int i = ShapeVec.size() - 1; i >= 0; i--)
	{
		if (ShapeVec[i]->Cantains(Click))
		{
			ShapeVec.erase(ShapeVec.begin() + i);
			return;
		}
	}

	
	/*
	bool Flag = false;
	int t = NoOfShapes;
	int count = 0;
	cout << "Stop1\n";

	for (int i = 0; i < t && !Flag; i++)
	{

		Flag = (*ShapePtr[i]).Cantains(Click);
		if (Flag==true)
		{
			delete ShapePtr[i];
			Flag = true;
			for (int j = i; j < (NoOfShapes-i); j++)
			{

				ShapePtr[j] = ShapePtr[j + 1];
			}
			NoOfShapes--;
		}
	}


	cout << NoOfShapes << " " << Capacity << endl;

	if (this->Capacity == 2 * (this->NoOfShapes))
	{
		Shape **temp;
		temp = new Shape*[NoOfShapes];
		for (int i = 0; i < this->NoOfShapes; i++)
			temp[i] = this->ShapePtr[i];
		delete[]this->ShapePtr;
		this->Capacity = this->Capacity / 2;
		this->ShapePtr = new Shape*[Capacity];
		for (int i = 0; i < this->NoOfShapes; i++)
			this->ShapePtr[i] = temp[i];
		for (int i = 0; i < NoOfShapes; i++)
		{
			delete temp[i];
		}
		delete []temp;
	}*/
}
void DrawingArea::PrintDrawingArea(const Point & cursor)
{
	for (int i = 0; i < ShapeVec.size(); i++)
		ShapeVec[i]->Draw();

	/*for (int i = 0; i < this->NoOfShapes; i++)
		ShapePtr[i]->Draw();
		*/
	DrawingArea::PrintCurrentCursorCoordinate(cursor); 
}
void DrawingArea::SaveDocument()
{
	ofstream Output("PaintBushFile.txt");

	Output << ShapeVec.size() << endl;
	Output << endl;
	for (int i = 0; i < ShapeVec.size(); i++)
	{
		const int temp = DetermineShapeType(i);
		Output<<temp<<" ";	//index of shape from panel corresponding
		
		if (temp>3)Output <<" "<<ShapeVec[i]->GetNoOfPoints() <<" ";	//store the track of no of point in case of curve and polygon
		
		int c = ShapeVec[i]->GetNoOfPoints();

		if (temp==0)
		{
			Circle * a =  static_cast <Circle*> (ShapeVec[i]);
			Point p = a->GetCenter();
			Output << a->GetRadius()<<" ";
			Output << p.x <<" ";
			Output << p.y <<" ";
			
			Color_RGB c = ShapeVec[i]->GetShapeColor();
			Output << c.GetR_value() << " " << c.GetG_value() << " " << c.GetB_value()<<" ";
			bool flag=(*a).GetFilledStatus();
			
			if (flag == true)
			{
				Output << "1 ";
				Color_RGB c = (*a).GetFilledColor();
				Output << " " << c.GetR_value() << " " << c.GetG_value() << " " << c.GetB_value();
			}
			else Output << " 0";
		}
		else
		{
			for (int j = 0; j < c; j++)
			{
				Point p = ShapeVec[i]->GetPoint(j);
				Output << p.x << " " << p.y;
				if (j != c - 1)
					Output << "   ";
			}
			Color_RGB c = ShapeVec[i]->GetShapeColor();
			Output <<" "<< c.GetR_value() << " " << c.GetG_value() << " " << c.GetB_value();

			if ( temp == 1 || temp == 3 || temp == 5)
			{
				
				Polygon * a = static_cast <Polygon*> (ShapeVec[i]);
				bool flag = (*a).IsPolygonFilled();
				if (flag == true)
				{
					Output << " 1 ";
					Color_RGB c = (*a).GetFilledColor();
					Output << " " << c.GetR_value() << " " << c.GetG_value() << " " << c.GetB_value();
				}
				else
					Output << " 0 ";
			}
			else Output << " 0 ";
			

		}
		Output << endl;
	}
}
void DrawingArea::LoadDocument()
{
	ShapeVec.clear();
	ifstream Input("PaintBushFile.txt");
	int TotalShapes = 0, ShapeIndex = 0;
	Input >> TotalShapes;
	Point *TempList;
	bool flag = false;
	for (int i = 0; i < TotalShapes; i++)
	{
		Input >> ShapeIndex;
		if (ShapeIndex==0)
		{
			TempList = new Point[1];
			Color_RGB color;
			float R;
			Input >> R;
			LoadPointsFromFile(1, Input , TempList,color);
			ShapeVec.push_back(new Circle( TempList[0],R));
			ShapeVec[i]->SetShapeColor(color);
		}
		else 
		if (ShapeIndex == 1)
		{
			TempList = new Point[2];
			Color_RGB color;
			LoadPointsFromFile(2, Input, TempList, color);
			ShapeVec.push_back(new Rectangle(TempList[0], TempList[1]));
			ShapeVec[i]->SetShapeColor(color);

		}
		else
		if (ShapeIndex == 2)
		{
			TempList = new Point[2];
			Color_RGB color;
			LoadPointsFromFile(2, Input, TempList, color);
			ShapeVec.push_back(new Line(TempList[0], TempList[1]));
			ShapeVec[i]->SetShapeColor(color);
		}
		else
		if (ShapeIndex == 3)
		{
			TempList = new Point[3];
			Color_RGB color;
			LoadPointsFromFile(3, Input, TempList, color);
			ShapeVec.push_back(new Triangle(TempList[0], TempList[1],   TempList[2]));
			ShapeVec[i]->SetShapeColor(color);
		}
		else
		if (ShapeIndex == 4)
		{
			int T;
			Color_RGB color;
			Input >> T;
			TempList = new Point[T];
			LoadPointsFromFile(T, Input, TempList, color);
			ShapeVec.push_back(new Curve(T,TempList));
			ShapeVec[i]->SetShapeColor(color);
		}
		else
		if (ShapeIndex == 5)
		{
			int T;
			Color_RGB color;
			Input >> T;
			TempList = new Point[T];
			LoadPointsFromFile(T, Input, TempList, color);
			ShapeVec.push_back(new Polygon(T, TempList));
			ShapeVec[i]->SetShapeColor(color);
		}
		Input >> flag;
		if (flag == true){
			float r, g, b;
			Input >> r >> g >> b;
			Color_RGB m(r, g, b);
			ShapeVec[i]->Fill(m);
		}
	}
}
void DrawingArea::LoadPointsFromFile(int NoOfPoints, ifstream & Input, Point *List , Color_RGB & _C)
{
	for (int i = 0; i < NoOfPoints; i++)
	{
		Input >> List[i].x;
		Input >> List[i].y;
	}
	float r,g,b;
	Input >> r >> g >> b;
	_C.SetColor(r,g,b);
}
int DrawingArea::DetermineShapeType(const int index)
{
	Circle* Cir = dynamic_cast<Circle*>(ShapeVec[index]);
	if (Cir != nullptr)
	{
		return 0;
	}
	Rectangle* Rec = dynamic_cast<Rectangle*>(ShapeVec[index]);
	if (Rec != nullptr)
	{
		return 1;
	}
	Line* L= dynamic_cast<Line*>(ShapeVec[index]);
	if (L != nullptr)
	{
		return 2;
	}
	Triangle* Tri = dynamic_cast<Triangle*>(ShapeVec[index]);
	if (Tri != nullptr)
	{
		return 3;
	}
	Curve* Cur = dynamic_cast<Curve*>(ShapeVec[index]);
	if (Cur != nullptr)
	{
		return 4;
	}
	Polygon* Pol = dynamic_cast<Polygon*>(ShapeVec[index]);
	if (Pol != nullptr)
	{
		return 5;
	}

}
DrawingArea::~DrawingArea()
{
	for (int i = 0; i < ShapeVec.size(); i++)
	{
		delete ShapeVec[i];
	}

	//for (int i = 0; i < NoOfShapes; i++)
	//{
	//	delete [i]ShapePtr;
	//}
	//delete []ShapePtr;
	//ShapePtr =nullptr;
}
void DrawingArea::PrintCurrentCursorCoordinate(const Point & cursor)
{
	int integer = cursor.GetY();
	int mode;
	char a[6];
	int i = 0;
	while (integer>9)
	{
		mode = integer % 10;
		integer = floor(integer / 10);
		a[i] = char(48 + mode);
		i++;
	}
	a[i] = char(48 + integer);
	for (int j = 0; j < (i / 2); j++)
		swap(a[j], a[i - j]);
	i++;
	a[i] = ')';
	a[i+1] = '\0';

	PrintString(a, 1305, 10);
	
	//x axis
	int temp = cursor.GetX();
	if (temp==0)
		temp = 1;
	int arr_length= floor(log10(abs(temp)));		//calculating the length size
	arr_length++;
	char abc[6];
	integer = abs(cursor.GetX()), mode = 0, i = (arr_length - 1) +1 ;
	abc[i+1] = ',';
	while (integer>9)
	{
		mode = integer % 10;
		integer = floor(integer / 10);
		abc[i] =char(48+ mode );
		i--;
	}
	abc[i] = char(48+integer);

	abc[0] = '(';
	PrintString(abc, 1240, 10);
}