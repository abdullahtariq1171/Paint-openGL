#include <iostream>
using namespace std;
#include <fstream>
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include "Line.h"
#include "Point.h"
#include <glut.h>

float **ColorTray;
int Tcolor;


bool flagg;
const int WinSizeX = 1350, WinSizeY = 690;
// const int WinSizeX = 500, WinSizeY = 500;
int x_value=10, y_value = 0;
char key_pressed = '\0';
Point clicked(0,0);
bool click = false;
#define FONT			GLUT_BITMAP_HELVETICA_18
#define CHAR_H			5
#define LINE_SEP		1
void emitString(char s[], int tx, int ty)
{
	int x, y;

	x = tx;
	y = ty;
	int i = 0;
	int width;
	while (s[i] != '\0') {
		width = glutBitmapWidth(FONT, s[i]);
		if (s[i] == '\n') {
			x = tx;
			y += CHAR_H + LINE_SEP;
		}
		else {
			glRasterPos2i(x, y);
			glutBitmapCharacter(FONT, s[i]);
			x += width;
		}
		++i;
	}
}
void keyCB(unsigned char key, int x, int y)	/* called on key press */
{
	key_pressed = key;
	if (key == 'q') exit(0);
}
void mouseB(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN){
			std::cout << "Button Left, State Down" << endl;
			click = true;
			x_value = x;
			y_value = WinSizeY- y;
			clicked.SetX(x_value);
			clicked.SetY(y_value);
		}
		if (state == GLUT_UP)
			std::cout << "Button Left, State Up" << endl;

		cout << "Position Of x=" << x << "Position Of y=" << y << endl;
	}

	if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_DOWN)
			std::cout << "Button Right, State Down" << endl;

		if (state == GLUT_UP)
			std::cout << "Button Right, State Up" << endl;

		cout << "Position Of x=" << x << "Position Of y=" << y << endl;
	}
}
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	/* set background to white */
	glColor3f(0.0f, 1.0f, 0.0f); /* set drwaing color to black */
	glPointSize(5.0); /* setting the point size to 4 by 4 pixel */
	gluOrtho2D(0, WinSizeX, 0, WinSizeY);		/* how object is mapped to window */
	return;
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
	}
	else cout << "[color_panel_data.txt] not open\n";
}
//void DrawDrawingBoard()
//{
//
//	UploadColorsFromFile(ColorTray, Tcolor);

	/*for (GLint i = 0; i < 18; i++)
		cout << ColorTray[i][0] << "_" << ColorTray[i][1]<< "_" << ColorTray[i][2] << endl;*/
//
//	int BoardX = 20, BoardY = WinSizeY - 10;
//
//	Point P1(BoardX, BoardY);
//	P1.Draw();
//	Point P2(BoardX + WinSizeX - 40, BoardY - 90);
//	P2.Draw();
//	//	Outer Board Box
//	Rectangle Outer(P1, P2);
//	Outer.FilledStatus(false);
//	Outer.SetShapeColor(0.847059, 0.847059, 0.74902);
//	Outer.Draw();
//
//
//	//TOOL BOXEX START FROM HERE
//	int ToolBoxX = BoardX + 20, ToolBoxY = BoardY - 5;
//	Rectangle ToolBox(ToolBoxX, ToolBoxY, ToolBoxX + 210, ToolBoxY - 80);
//	ToolBox.FilledStatus(false);
////	ToolBox.Draw();
//	int ToolBoxexSize = 34;
//	int tempX = ToolBoxX + 4, tempY = ToolBoxY - 4;
//	Rectangle *ToolBoxPtr = new Rectangle[8];
//
//
//	Rectangle TT(tempX, tempY, tempX + ToolBoxexSize, tempY - ToolBoxexSize);
//	TT.Draw();
////	for (int i = 0; i < 8; i++)
////	{
////		ToolBoxPtr[i].SetP1x(tempX);
////		ToolBoxPtr[i].SetP1y(tempY);
////		ToolBoxPtr[i].SetP2x(tempX + ToolBoxexSize);
////		ToolBoxPtr[i].SetP2y(tempY - ToolBoxexSize);
////		tempX += ToolBoxexSize + 4;
//////		ToolBoxPtr[i].SetFilledColor(ColorTray[i][0], ColorTray[i][1], ColorTray[i][2]);
////		ToolBoxPtr[i].FilledStatus(true);
////		ToolBoxPtr[i].Draw();
////		if ((i + 1) == 4){
////			tempY -= (ToolBoxexSize + 4);
////			tempX = ToolBoxX + 4;
////		}
////	}
//
//	Rectangle SelectedToolBox(ToolBoxX + 156, ToolBoxY - 4, ToolBoxX + 206, ToolBoxY - 4 - 50);
//	SelectedToolBox.SetFilledColor(0, 0, 0);
//	SelectedToolBox.FilledStatus(false);
//	SelectedToolBox.Draw();
//
//
//	int ColorBoxX = BoardX + 800, ColorBoxY = BoardY - 5;
//	Rectangle ColorBox(ColorBoxX, ColorBoxY, ColorBoxX + 220, ColorBoxY - 80);
//
////	Rectangle ColorBox(tempX, tempY, tempX + ToolBoxexSize, tempY - ToolBoxexSize);
//	ColorBox.FilledStatus(false);
//	ColorBox.Draw();
//
//
//	int Square_boxSize = 21.5;
//	tempX = ColorBoxX + 6, tempY = ColorBoxY - 5;
//	Rectangle *ColorBoxPtr = new Rectangle[18];
//	for (int i = 0; i < 18; i++)
//	{
//		ColorBoxPtr[0].SetP1x(400);
//		ColorBoxPtr[0].SetP1y(800);
//		ColorBoxPtr[0].SetP2x(700);
//		ColorBoxPtr[0].SetP2y(800);
////		tempX += Square_boxSize + 4;
//		ColorBoxPtr[0].SetFilledColor(ColorTray[4][0], ColorTray[4][1], ColorTray[4][2]);
//		ColorBoxPtr[0].Draw();
	/*	if ((i + 1) % 6 == 0 && i != 17){
			tempY -= (Square_boxSize + 4);
			tempX = ColorBoxX + 6;
		}
	}*/
	//int SelectedColorIndex = 0;
	//bool BreakLoop = false;
	////picking the color
	//if (click == true)
	//{
	//	click = false;
	//	if (ColorBox.Cantains(clicked))
	//	{
	//		for (int i = 0; i < 18; i++ && !BreakLoop)
	//		{
	//			if (ColorBoxPtr[i].Cantains(clicked))
	//			{
	//				BreakLoop = true;
	//				SelectedColorIndex = i;
	//			}
	//		}
	//	}
	//}
	//Rectangle SelectedColorBox(tempX + 4, ColorBoxY - 5, tempX + 5 + 50, ColorBoxY - 5 - 50);
	//if (BreakLoop){
	//	SelectedColorBox.SetFilledColor(ColorTray[SelectedColorIndex][0], ColorTray[SelectedColorIndex][1], ColorTray[SelectedColorIndex][2]);
	//}
	//SelectedColorBox.Draw();



	/*delete[]ColorBoxPtr;
	ColorBoxPtr = nullptr;
	delete[]ColorTray;
	ColorTray = nullptr;*/
//}
void DrawDrawingBoard()
{
	float **ColorTray;
	int Tcolor;
	UploadColorsFromFile(ColorTray, Tcolor);
	int BoardX = 20, BoardY = WinSizeY - 10;

	Point P1(BoardX, BoardY);
	P1.Draw();
	Point P2(BoardX + WinSizeX - 40, BoardY - 90);
	P2.Draw();
	//	Outer Board Box
	Rectangle Outer(P1, P2);
	Outer.FilledStatus(false);
	Outer.SetFilledColor(0.847059, 0.847059, 0.74902);
	Outer.Draw();


	//TOOL BOXEX START FROM HERE
	int ToolBoxX = BoardX + 20, ToolBoxY = BoardY - 5;
	//Rectangle ToolBox(ToolBoxX, ToolBoxY, ToolBoxX + 210, ToolBoxY - 80);
	//ToolBox.FilledStatus(false);
	//ToolBox.Draw();
	//int ToolBoxexSize = 34;
	//int tempX = ToolBoxX + 4, tempY = ToolBoxY - 4;
	//Rectangle *ToolBoxPtr = new Rectangle[8];
//	for (int i = 0; i < 8; i++)
//	{
//		ToolBoxPtr[i].SetP1x(tempX);
//		ToolBoxPtr[i].SetP1y(tempY);
//		ToolBoxPtr[i].SetP2x(tempX + ToolBoxexSize);
//		ToolBoxPtr[i].SetP2y(tempY - ToolBoxexSize);
//		tempX += ToolBoxexSize + 4;
//		ToolBoxPtr[i].SetFilledColor(ColorTray[i][0], ColorTray[i][1], ColorTray[i][2]);
////		ToolBoxPtr[i].SetFilledColor(0, 0, 0);
//		ToolBoxPtr[i].FilledStatus(false);
//		ToolBoxPtr[i].Draw();
//		if ((i + 1) == 4){
//			tempY -= (ToolBoxexSize + 4);
//			tempX = ToolBoxX + 4;
//		}
//	}
//
	Rectangle SelectedToolBox(ToolBoxX + 156, ToolBoxY - 4, ToolBoxX + 206, ToolBoxY - 4 - 50);
	SelectedToolBox.SetFilledColor(0, 0, 0);
	SelectedToolBox.FilledStatus(false);
	SelectedToolBox.Draw();


	int ColorBoxX = BoardX + 800, ColorBoxY = BoardY - 5;
	Rectangle ColorBox(ColorBoxX, ColorBoxY, ColorBoxX + 220, ColorBoxY - 80);
	ColorBox.FilledStatus(false);
	ColorBox.Draw();


	int Square_boxSize = 21.5;
	int tempX = ColorBoxX + 6, tempY = ColorBoxY - 5;
	Rectangle *ColorBoxPtr = new Rectangle[18];
	for (int i = 0; i < 18; i++)
	{
		ColorBoxPtr[i].SetP1x(tempX);
		ColorBoxPtr[i].SetP1y(tempY);
		ColorBoxPtr[i].SetP2x(tempX + Square_boxSize);
		ColorBoxPtr[i].SetP2y(tempY - Square_boxSize);
		tempX += Square_boxSize + 4;
		ColorBoxPtr[i].SetFilledColor(ColorTray[i][0], ColorTray[i][1], ColorTray[i][2]);
		ColorBoxPtr[i].Draw();
		if ((i + 1) % 6 == 0 && i != 17){
			tempY -= (Square_boxSize + 4);
			tempX = ColorBoxX + 6;
		}
	}


	//picking the color
	/*if (click == true)
	{
		click = false;
		if (ColorBox.Cantains(Clicked))
		{
			bool BreakLoop = false;
			for (int i = 0; i < 18; i++ && !BreakLoop)
			{
				if (ColorBoxPtr[i].IsExistInside(Clicked))
				{
					BreakLoop = true;
					SeletedColor.SetColor(ColorTray[i][0], ColorTray[i][1], ColorTray[i][2]);
				}
			}
		}
	}*/
	Rectangle SelectedColorBox(tempX + 4, ColorBoxY - 5, tempX + 5 + 50, ColorBoxY - 5 - 50);
	SelectedColorBox.SetFilledColor(0.847059, 0, 0);
//	SelectedColorBox.SetFilledColor(SeletedColor.GetR_value(), SeletedColor.GetG_value(), SeletedColor.GetB_value());
	SelectedColorBox.Draw();



	delete[]ColorBoxPtr;
	ColorBoxPtr = nullptr;
	delete[]ColorTray;
	ColorTray = nullptr;
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear the screen 
	
	
	DrawDrawingBoard();

	//Rectangle a(400, 600, 800, 600);
	//a.Draw();

	//Circle a(300, 300, 30);

	//if (click)
	//{
	//	click = false;
	//	cout<<a.Cantains(clicked);
	//	cout << endl;
	//}
	//Shape *b;
	//b = &a;
	//(*b).Draw();


	//Rectangle A(1000, 200 , 600,600);
	//b = &A;
	//(*b).Draw();
	//
	//Line L(50,50 , 1000,100);
	//b = &L;
	//(*b).Draw();


//	Point P1(100, 100), P2(400, 400);

//	cout<<P1.CalculateDistance(P2);
//	cout << endl;
	glFlush();				// Complete any pending operations 
	glutSwapBuffers();
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



	delete []ColorTray;
	ColorTray = nullptr;
	return 0;
}

