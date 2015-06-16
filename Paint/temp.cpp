#include <iostream>
using namespace std;
#include <fstream>
#include "Circle.h"
#include "Line.h"
#include "Point.h" 
#include "Polygon.h"
#include "Text.h"
#include "Color_RGB.h"
#include "Rectangle.h"
#include "Curve.h"
#include "conio.h"
#include <glut.h>
#include "DrawingArea.h"
#include <vector>
const int WinSizeX = 1350, WinSizeY = 690;
DrawingArea DrawingBoard;
int NoOfPointsRequire = 0,SeletedColorIndex = 0,SelectedShapeIndex=2;
char key_pressed = '\0';
bool Isclick = false,IsKeyPressd = false;
Point Clicked,*TempPointsPtr=nullptr;
int TempPointerPtrIndex = 0;
bool ShapeComplete=true;
float **ColorTray;
Shape *ShapeMainPtr=nullptr;
bool ShapeClick = false;
bool IsShapeCompleted = false;
//list 
void emitString(char s[], int tx, int ty)
{
#define FONT		GLUT_BITMAP_HELVETICA_18
#define CHAR_H		5
#define LINE_SEP	1
	int x, y;
	x = tx;
	y = ty;
	int i = 0;
	int width;
	while (s[i] != '\0')
	{
		width = glutBitmapWidth(FONT, s[i]);
		if (s[i] == '\n') 
		{
			cout << "Picked\n";
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
void UploadColorsFromFile(float  ** & ptr, int & total_colors)
{
	ifstream input("color_panel_data.txt");
	if (input.is_open()){
		input >> total_colors;
		ptr = new float*[total_colors];
		for (int i = 0; i < total_colors; i++)
			ptr[i] = new float[3];

		for (int i = 0; i < total_colors; i++){
			
			for (int j = 0; j < 3; j++)
				input >> ptr[i][j];
		}
	}	else cout << "[color_panel_data.txt] not open\n";
}
void PrintDifferentTool(const int & Index , const Point & Square_Point)
{
	if (Index==0)
	{
		Point P1(Square_Point.GetX() + 17, Square_Point.GetY()-18), P2(Square_Point.GetX() + 30, Square_Point.GetY()-18);
		Circle C_temp(P1, P2);
		C_temp.Draw();
	}
	else if (Index==1)
	{
		int x = Square_Point.GetX(), y = Square_Point.GetY();
		Rectangle temp(Square_Point.GetX() + 5, Square_Point.GetY() - 5, Square_Point.GetX() + 30, Square_Point.GetY() - 30);
		temp.FilledStatus(false);
		temp.Draw();
	}
	else if (Index == 2)
	{
		Line temp(Square_Point.GetX() + 5, Square_Point.GetY() - 5, Square_Point.GetX() + 30, Square_Point.GetY() - 30);
		temp.Draw();
	}
	else if (Index==3)
	{
		Rectangle temp(Square_Point.GetX() + 5, Square_Point.GetY() - 10, Square_Point.GetX() + 30, Square_Point.GetY() - 24);
		temp.FilledStatus(false);
		temp.Draw();
	}
	else if (Index==4)
	{
		const int Total_Points = 14;
		Point t[Total_Points];
		int x = 4, y = 20;
		for (int i = 0; i < Total_Points; i++)
		{
			t[i].SetX(Square_Point.GetX() + x), t[i].SetY(Square_Point.GetY() - y);
			x += 2;
			if (i < 6)
				y -= 2;
			else if (i == 6)
				y += 1;
			else y +=2;
		}
		Curve temp(Total_Points, t);
		temp.Draw();
	}
	else if (Index==5)
	{
		emitString("A", Square_Point.GetX() + 11, Square_Point.GetY() - 22);
	}
	else if (Index==6)
	{
		Point arr[3];
		arr[0].SetX(Square_Point.GetX() + 5), arr[0].SetY(Square_Point.GetY()-25);
		arr[1].SetX(Square_Point.GetX() + 13), arr[1].SetY(Square_Point.GetY()-5);
		arr[2].SetX(Square_Point.GetX() + 25), arr[2].SetY(Square_Point.GetY()-25);
		Polygon temp(3,arr);
		temp.Draw();
	}
}
void PrintToolBoxPanel(const int & BoardX, const int &BoardY)
{
	/*********************************************************[TOOL BOX PANEL START FROM HERE]*******************************************************/
	//TOOL BOXEX START FROM HERE
	int ToolBoxX = BoardX + 20, ToolBoxY = BoardY - 5;
	Rectangle ToolBox(ToolBoxX, ToolBoxY, ToolBoxX + 210, ToolBoxY - 80);
	ToolBox.FilledStatus(false);
	ToolBox.Draw();
	int ToolBoxexSize = 34;
	int tempX = ToolBoxX + 4, tempY = ToolBoxY - 4;
	Rectangle *ToolBoxPtr = new Rectangle[8];
	for (int i = 0; i < 8; i++)
	{
		ToolBoxPtr[i].SetP1x(tempX);
		ToolBoxPtr[i].SetP1y(tempY);
		ToolBoxPtr[i].SetP2x(tempX + ToolBoxexSize);
		ToolBoxPtr[i].SetP2y(tempY - ToolBoxexSize);
		tempX += ToolBoxexSize + 4;
		//		ToolBoxPtr[i].SetColor(ColorTray[i][0], ColorTray[i][1], ColorTray[i][2]);
		//		ToolBoxPtr[i].SetColor(0, 0, 0);
		ToolBoxPtr[i].FilledStatus(false);
		ToolBoxPtr[i].Draw();
		PrintDifferentTool(i,ToolBoxPtr[i].GetP1());
		if ((i + 1) == 4){
			tempY -= (ToolBoxexSize + 4);
			tempX = ToolBoxX + 4;
		}
	}

	Rectangle SelectedToolBox(ToolBoxX + 156, ToolBoxY - 4, ToolBoxX + 206, ToolBoxY - 4 - 50);
	Point _S(ToolBoxX + 162.5, ToolBoxY - 14);
	PrintDifferentTool(SelectedShapeIndex, _S);
	SelectedToolBox.FilledStatus(false);
	SelectedToolBox.Draw();
	/*********************************************************[TOOL BOX PANEL START END HERE]*******************************************************/

//SELECTION OF TOO START FROM HERE
	if (Isclick)
	{
		if (ToolBox.Cantains(Clicked))
		{
			bool BreakLoop = false;
			Isclick =false;
			for (int i = 0; i < 8; i++ && !BreakLoop)
			{
				if (ToolBoxPtr[i].Cantains(Clicked))
				{
					BreakLoop = true;
					SelectedShapeIndex = i;
				}
			}
		}
	}
	delete[]ToolBoxPtr;
	ToolBoxPtr = nullptr;
}
void PrintColorBoxPanel(const int & BoardX, const int &BoardY)
{
	int Tcolor;
	UploadColorsFromFile(ColorTray, Tcolor);
	/*********************************************************[COLOR BOX PANEL START FROM HERE]*******************************************************/
	//Color BOXEX START FROM HERE
	int ColorBoxX = BoardX + 500, ColorBoxY = BoardY - 5;
	Rectangle ColorBox(ColorBoxX, ColorBoxY, ColorBoxX + 210, ColorBoxY - 80);
	ColorBox.FilledStatus(false);
	ColorBox.Draw();
	int ColorBoxexSize = 21.5;
	int TempX = ColorBoxX + 4, TempY = ColorBoxY - 4;
	Rectangle *ColorBoxPtr = new Rectangle[18];
	for (int i = 0; i < 18; i++)
	{
		ColorBoxPtr[i].SetP1x(TempX);
		ColorBoxPtr[i].SetP1y(TempY);
		ColorBoxPtr[i].SetP2x(TempX + ColorBoxexSize);
		ColorBoxPtr[i].SetP2y(TempY - ColorBoxexSize);
		TempX += ColorBoxexSize + 4;
		ColorBoxPtr[i].SetFilledColor(ColorTray[i][0], ColorTray[i][1], ColorTray[i][2]);
		ColorBoxPtr[i].FilledStatus(true);
		ColorBoxPtr[i].Draw();
		if ((i + 1) % 6 == 0){
			TempY -= (ColorBoxexSize + 4);
			TempX = ColorBoxX + 4;
		}
	}
	/*********************************************************[COLOR BOX PANEL START END HERE]*******************************************************/
	Rectangle SelectedColorBox(ColorBoxX + 156, ColorBoxY - 4, ColorBoxX + 206, ColorBoxY - 4 - 50);
	SelectedColorBox.SetFilledColor(ColorTray[SeletedColorIndex][0], ColorTray[SeletedColorIndex][1], ColorTray[SeletedColorIndex][2]);
	SelectedColorBox.FilledStatus(true);
	SelectedColorBox.Draw();
	if (Isclick == true)
	{
		Isclick = false;
		if (ColorBox.Cantains(Clicked))
		{
			bool BreakLoop = false;

			for (int i = 0; i < 18; i++ && !BreakLoop)
			{
				if (ColorBoxPtr[i].Cantains(Clicked))
				{
					BreakLoop = true;
					SeletedColorIndex = i;
				}
			}
		}
	}
//	delete[]ColorTray;
//	ColorTray = nullptr;
	delete[]ColorBoxPtr;
	ColorBoxPtr = nullptr;
}
void DrawDrawingBoard()
{
	int BoardX = 1, BoardY = WinSizeY;
	Point P1(BoardX, BoardY),P2(BoardX + WinSizeX, BoardY-90);
	Rectangle Outer(P1, P2);
	Outer.FilledStatus(false);
	Outer.Draw();
	PrintToolBoxPanel(BoardX,BoardY);
	PrintColorBoxPanel(BoardX, BoardY);
}
void keyCB(unsigned char key, int x, int y)	/* called on key press */
{
	key_pressed = key;
	IsKeyPressd= true;
	if (key == 'q') exit(0);
}
void PrintDifferentShapes()
{
	if (Clicked.GetY() < (WinSizeY - 90) && ShapeClick==true)
	{
		cout << "click ho gyaaaaaaaaaaaaaaaaaa\n";
		//system("pause");
		ShapeClick = false;
		/*	if (IsShapeCompleted)
		{
			cout << "first\n\n";
			IsShapeCompleted = false;
			TempPointsPtr = new Point[2];
			TempPointsPtr[TempPointerPtrIndex] = Clicked;
			TempPointerPtrIndex++;
		}
		else 
		{
			cout << "Second\n\n";
			TempPointsPtr[TempPointerPtrIndex] = Clicked;
			TempPointerPtrIndex++;
		}
		if (TempPointerPtrIndex == 2)
		{
			cout << "completed";
			DrawingBoard.add(SelectedShapeIndex, TempPointsPtr);
			delete	[]TempPointsPtr;
			TempPointsPtr = nullptr;
			TempPointerPtrIndex = 0;
			IsShapeCompleted = true;
		}*/
	}
	DrawingBoard.PrintDrawingArea();
}
void mouseB(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) 
	{
		ShapeClick = true;
		Isclick = true;
		if (state == GLUT_DOWN)
		{
			std::cout << "Button Left, State Down" << endl;
			Isclick = true;
			Clicked.SetPoint(x, WinSizeY-y);
		}
		if (state == GLUT_UP)
			std::cout << "Button Left, State Up" << endl;

		cout << "Position Of x=" << x << "Position Of y=" << y << endl;
	}
	else
	if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_DOWN)
			std::cout << "Button Right, State Down" << endl;

		if (state == GLUT_UP)
			std::cout << "Button Right, State Up" << endl;

		cout << "Position Of x=" << x << "Position Of y=" << y << endl;
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear the screen 

	DrawDrawingBoard();
	PrintDifferentShapes();

	glFlush();				// Complete any pending operations 
	glutSwapBuffers();
	return;
}
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	/* set background to white */
	glColor3f(0.0f, 1.0f, 0.0f); /* set drwaing color to black */
	glPointSize(5.0); /* setting the point size to 4 by 4 pixel */
	gluOrtho2D(0, WinSizeX, 0, WinSizeY);		/* how object is mapped to window */
	return;
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);		/* initialize GLUT system */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WinSizeX, WinSizeY); 
	glutCreateWindow("PAINT BRUSH");	/* create window */
	glutDisplayFunc(display);// register callbacks
	glutIdleFunc(display);			/* set window's idle callback */
	glutKeyboardFunc(keyCB);		/* set window's key callback */
	glutMouseFunc(mouseB);		/* set window's mouse callback */
	myInit();
	glutMainLoop();			/* start processing events... */

	//delete[]TempPointsPtr;
	return 0;
}
