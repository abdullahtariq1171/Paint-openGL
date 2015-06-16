#include "conio.h"
#include <string>
#include <fstream>
#include "DrawingArea.h"
#pragma warning(disable: 4996)

Color_RGB SelectedColor;
int NoOfPointsClicked = 0 , CapacityForPoints=0;
 const int WinSizeX = 1350, WinSizeY = 690;
DrawingArea DrawingBoard;
int  SeletedColorIndex = 0, SelectedShapeIndex = 0, PointsRequired = 0, TempPointerPtrIndex = 0;
bool LeftClick = false,RightClick=false, IsKeyPressd = false;
Point Clicked, MovingPosition, *TempPointsPtr = nullptr;
bool ShapeComplete = true;
float **ColorTray;
bool ShapeClick = false, IsShapeCompleted = true, IsCursorMoved = false;

void emitString(char s[], int tx, int ty)
{
	#define FONT			GLUT_BITMAP_TIMES_ROMAN_24
	#define CHAR_H			18
	#define LINE_SEP		4

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
void FillColorTray(float  ** & ptr, int & total_colors)
{/*
	total_colors = 18;

	 ptr = new float*[18];
	for (int i = 0; i < 18; i++)
	{
		ptr[i] = new float[3];
		ptr[i][0] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		ptr[i][1] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		ptr[i][2] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	}*/

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
void PrintDifferentTool(const int & Index, const Point & Square_Point)
{
	if (Index == 0)
	{
		Point P1(Square_Point.GetX() + 17, Square_Point.GetY() - 18), P2(Square_Point.GetX() + 30, Square_Point.GetY() - 18);
		Circle C_temp(P1, P2);
		C_temp.Draw();
	}
	else if (Index == 1)
	{
		Rectangle temp(Square_Point.GetX() + 5, Square_Point.GetY() - 10, Square_Point.GetX() + 30, Square_Point.GetY() - 24);
		temp.FilledStatus(false);
		temp.Draw();

	}
	else if (Index == 2)
	{
		Line temp(Square_Point.GetX() + 5, Square_Point.GetY() - 5, Square_Point.GetX() + 30, Square_Point.GetY() - 30);
		temp.Draw();
	}
	else if (Index == 3)
	{
		Point arr[3];
		arr[0].SetX(Square_Point.GetX() + 5), arr[0].SetY(Square_Point.GetY() - 25);
		arr[1].SetX(Square_Point.GetX() + 13), arr[1].SetY(Square_Point.GetY() - 5);
		arr[2].SetX(Square_Point.GetX() + 25), arr[2].SetY(Square_Point.GetY() - 25);
		Polygon temp(3, arr);
		temp.Draw();
	}
	else if (Index == 4)
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
			else y += 2;
		}
		Curve temp(Total_Points, t);
		temp.Draw();
	}
	else if (Index == 5)
	{
		Point arr[5];
		arr[0].SetX(Square_Point.GetX() + 5), arr[0].SetY(Square_Point.GetY() - 28);
		arr[1].SetX(Square_Point.GetX() + 5), arr[1].SetY(Square_Point.GetY() - 10);
		arr[2].SetX(Square_Point.GetX() + 15), arr[2].SetY(Square_Point.GetY() - 3);
		arr[3].SetX(Square_Point.GetX() + 25), arr[3].SetY(Square_Point.GetY() - 10);
		arr[4].SetX(Square_Point.GetX() + 25), arr[4].SetY(Square_Point.GetY() - 28);
		Polygon temp(5, arr);
		temp.Draw();
	}
	else if (Index == 6)
	{
		Point arr[6];
		arr[0].SetX(Square_Point.GetX() + 5), arr[0].SetY(Square_Point.GetY() - 11);
		arr[1].SetX(Square_Point.GetX() + 20), arr[1].SetY(Square_Point.GetY() - 29);
		arr[2].SetX(Square_Point.GetX() + 30), arr[2].SetY(Square_Point.GetY() - 25);
		arr[3].SetX(Square_Point.GetX() + 15), arr[3].SetY(Square_Point.GetY() - 5);
		arr[4].SetX(Square_Point.GetX() + 2), arr[4].SetY(Square_Point.GetY() - 9);
		arr[5].SetX(Square_Point.GetX() + 2), arr[5].SetY(Square_Point.GetY() - 11);

		Polygon temp(6, arr);
		temp.Draw();
	}
	else if (Index == 7)
	{
		Point arr[5];
		arr[0].SetX(Square_Point.GetX() + 30), arr[3].SetY(Square_Point.GetY() - 12);
		arr[1].SetX(Square_Point.GetX() + 15), arr[1].SetY(Square_Point.GetY() - 28);
		arr[2].SetX(Square_Point.GetX() + 5), arr[2].SetY(Square_Point.GetY() - 28);
		arr[3].SetX(Square_Point.GetX() +20), arr[0].SetY(Square_Point.GetY() - 12);
		Polygon temp(4, arr);
		temp.Draw();
	}
}
void PrintToolBoxPanel(const int & BoardX, const int &BoardY)
{
	/*********************************************************[TOOL BOX PANEL START FROM HERE]*******************************************************/
	//TOOL BOXEX START FROM HERE
	int ToolBoxX = BoardX + 190, ToolBoxY = BoardY - 5;
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
		ToolBoxPtr[i].FilledStatus(false);
		ToolBoxPtr[i].Draw();
		PrintDifferentTool(i, ToolBoxPtr[i].GetP1());
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
	if (LeftClick)
	{
		if (ToolBox.Cantains(Clicked))
		{
			bool BreakLoop = false;
			LeftClick = false;
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

	/*********************************************************[COLOR BOX PANEL START FROM HERE]*******************************************************/
	//Color BOXEX START FROM HERE
	int ColorBoxX = BoardX + 410, ColorBoxY = BoardY - 5;
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
		ColorBoxPtr[i].SpecialDraw();
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
	if (LeftClick == true)
	{
		LeftClick = false;
		if (ColorBox.Cantains(Clicked))
		{
			bool BreakLoop = false;

			for (int i = 0; i < 18; i++ && !BreakLoop)
			{
				if (ColorBoxPtr[i].Cantains(Clicked))
				{
					BreakLoop = true;
					SeletedColorIndex = i;
					SelectedColor.SetColor(ColorTray[SeletedColorIndex][0], ColorTray[SeletedColorIndex][1], ColorTray[SeletedColorIndex][2]);
				}
			}
		}
	}
	
	delete[]ColorBoxPtr;
	ColorBoxPtr = nullptr;
}
void DrawDrawingBoard()
{	
	int BoardX = 1, BoardY = WinSizeY;
	Point P1(BoardX, BoardY), P2(BoardX + WinSizeX, BoardY - 90);
	Rectangle Outer(P1, P2);
	Outer.FilledStatus(true);

	Outer.SetFilledColor(1,1,1);
	Outer.SetShapeColor(0, 0, 0);
	Outer.Draw();
	P1.SetPoint(10, WinSizeY- 10);
	P2.SetPoint(90, WinSizeY - 80);

	Rectangle GetNewDocumentBox(P1,P2);
	GetNewDocumentBox.Draw();
	emitString("New", 25, WinSizeY- 50);
	if (GetNewDocumentBox.Cantains(Clicked) && ShapeClick)
	{
		ShapeClick = false;
		delete []TempPointsPtr;
		TempPointsPtr = nullptr, TempPointerPtrIndex = 0, PointsRequired = 0;
		DrawingBoard.GetNewDocument();
	}
	P1.x = P2.x +10;
	P2.x += 90;
	Rectangle SavePlusLoad(P1, P2);
	SavePlusLoad.Draw();
	Rectangle Save(P1.x + 10, P1.y - 7, P2.x - 10, P1.y - 32);
	Save.Draw();
	emitString("Save" ,P1.x+16 , P1.y-28);
	Rectangle Load(P1.x + 10, P1.y - 38, P2.x - 10, P2.y + 7);
 	Load.Draw();
	emitString("Load", P1.x + 15, P2.y + 12);

	if (Load.Cantains(Clicked)){
		DrawingBoard.LoadDocument();
	//	Clicked.x = 15;
	}
	else if (Save.Cantains(Clicked))
		DrawingBoard.SaveDocument();

	for (int i = 0; i < TempPointerPtrIndex; i++)
		TempPointsPtr[i].Draw();
	PrintToolBoxPanel(BoardX, BoardY);
 	PrintColorBoxPanel(BoardX, BoardY);
}
void PrintDifferentShapes()
{
	if (Clicked.GetY() < (WinSizeY - 90) && ShapeClick == true)
	{
		ShapeClick = false;
		if (SelectedShapeIndex==6)
		{
			DrawingBoard.Filling(Clicked , SelectedColor);
			return;
		}
		else if (SelectedShapeIndex == 7)
		{
			DrawingBoard.Deleting(Clicked);
			return;
		}
		if (IsShapeCompleted)
		{
			IsShapeCompleted = false;
			if (SelectedShapeIndex < 3)	//two poitns shapes
			{
				PointsRequired = 2;
				TempPointsPtr = new Point[2];
				TempPointsPtr[TempPointerPtrIndex] = Clicked;
				TempPointerPtrIndex++;
				CapacityForPoints = 2;
			}
			else if (SelectedShapeIndex == 3)
			{
				PointsRequired = 3;
				TempPointsPtr = new Point[3];
				TempPointsPtr[TempPointerPtrIndex] = Clicked;
				TempPointerPtrIndex++;
				CapacityForPoints = 3;
				
			}
			else if (SelectedShapeIndex == 4 || SelectedShapeIndex==5)
			{
				CapacityForPoints = 2;
				TempPointsPtr = new Point[CapacityForPoints];
				TempPointerPtrIndex = 0;
				TempPointsPtr[TempPointerPtrIndex] = Clicked;
				TempPointerPtrIndex++;
				NoOfPointsClicked++;
			}
		}
		else
		{
			if (CapacityForPoints == NoOfPointsClicked)
			{
				Point *t = new Point[NoOfPointsClicked];
				for (int i = 0; i < NoOfPointsClicked; i++)
				{
					t[i] = TempPointsPtr[i];
				}
				delete []TempPointsPtr;
				CapacityForPoints = CapacityForPoints * 2;
				TempPointsPtr = new Point[CapacityForPoints];
				for (int i = 0; i < NoOfPointsClicked; i++)
				{
					TempPointsPtr[i] = t[i];
				}
			}
			TempPointsPtr[TempPointerPtrIndex] = Clicked;
			TempPointerPtrIndex++;
			NoOfPointsClicked++;
		}
		cout << "Right click +" << RightClick << endl;
		if (IsShapeCompleted==false && (TempPointerPtrIndex == PointsRequired || RightClick))
		{
			RightClick = false;
			IsShapeCompleted = true;
			ShapeClick = false;
			TempPointerPtrIndex = 0;
			PointsRequired = 0;
			cout << "Before Adding Function\n";
			DrawingBoard.add(SelectedShapeIndex, TempPointsPtr, NoOfPointsClicked, SelectedColor);
			NoOfPointsClicked = 0;
			CapacityForPoints = 0;
			delete []TempPointsPtr;
			TempPointsPtr = nullptr;
		}
		cout << "Right click +" << RightClick << endl;

	}
}
void ChangeCursorWithCursorMotion(int x, int y)
{
	IsCursorMoved = true;
	y = WinSizeY - y;
	MovingPosition.SetPoint(x, y);
	if (y<WinSizeY - 90)
	{
		glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	}
	else
	{
		glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
	}

}
void mouseB(int button, int state, int x, int y)
{

	cout << x<<" "<<y << endl;
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			std::cout << "Button Left, State Down" << endl;
			LeftClick = true;
			ShapeClick = true;
			Clicked.SetPoint(x, WinSizeY - y);
		}
		else
		if (state == GLUT_UP)
		{
			std::cout << "Button Left, State Up" << endl;
		}

		cout << "Position Of x=" << x << "Position Of y=" << y << endl;
	}
	else
	if (button == GLUT_RIGHT_BUTTON)
	{
		if ((SelectedShapeIndex == 4 || SelectedShapeIndex == 5)  && !IsShapeCompleted)
		{
			RightClick = true;
			ShapeClick = true;
			Clicked.SetPoint(x, WinSizeY - y);
		}
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
	PrintDifferentShapes();
	DrawingBoard.PrintDrawingArea(MovingPosition);
	DrawDrawingBoard();
	glFlush();				// Complete any pending operations 
	glutSwapBuffers();
	return;
}
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);	/* set background to white */
	glColor3f(0.0f, 1.0f, 0.0f); /* set drwaing color to black */
	glPointSize(3.0); /* setting the point size to 4 by 4 pixel */
	gluOrtho2D(0, WinSizeX, 0, WinSizeY);		/* how object is mapped to window */
}
int main(int argc, char **argv)
{
	int Tcolor;
	FillColorTray(ColorTray, Tcolor);
	
	glutInit(&argc, argv);		/* initialize GLUT system */
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(WinSizeX, WinSizeY);
	
	glutCreateWindow("PAINT BRUSH");	//create window */
	glutDisplayFunc(display);// register callbacks
	glutIdleFunc(display);			/* set window's idle callback */
	glutMouseFunc(mouseB);		/* set window's mouse callback */
	myInit();
	glutSetCursor(GLUT_CURSOR_FULL_CROSSHAIR);
	glutPassiveMotionFunc(ChangeCursorWithCursorMotion);


	glutMainLoop();			/* start processing events... */

	if (TempPointsPtr!=nullptr)
		delete []TempPointsPtr;
	
	delete[]ColorTray;
	ColorTray = nullptr;
	return 0;
}

