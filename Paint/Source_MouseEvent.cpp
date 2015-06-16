#include <iostream>
#include <glut.h>

using namespace std;
bool click = false;
int x_value=0, y_value=0;
void myInit(void){

	glClearColor(1.0, 1.0, 1.0, 0.0);	/* set background to white */
	glColor3f(0.0f, 1.0f, 0.0f); /* set drwaing color to black */
	glPointSize(5.0); /* setting the point size to 4 by 4 pixel */
	gluOrtho2D(0, 500, 0, 500);		/* how object is mapped to window */
}
void displayScene(void) {

	glClear(GL_COLOR_BUFFER_BIT); //clear the screen

	glColor3f(0.0f, 1.0f, 0.0f);
	if (click){
		//Drawing Points
		glBegin(GL_POINTS);
			glVertex2i(x_value, 500-y_value);	
		glEnd();
	}
	glFlush();	//send all output to display.
	glutSwapBuffers();
}



void mouseB(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN){
		std::cout<< "Button Left, State Down"<<endl;
		click = true;
		x_value = x;
		y_value = y;
		}
		if (state == GLUT_UP)
			std::cout << "Button Left, State Up" << endl;
		
		cout << "Position Of x=" << x << "Position Of y=" << y<<endl;
	}

	if (button == GLUT_RIGHT_BUTTON) {
		if (state == GLUT_DOWN)
			std::cout << "Button Right, State Down" << endl;

		if (state == GLUT_UP)
			std::cout << "Button Right, State Up" << endl;
		
		cout << "Position Of x=" << x << "Position Of y=" << y << endl;

	}
}

int main(int argc, char **argv) {

	int win;

	int winx = 500;
	int winy = 500;
	glutInit(&argc, argv);		/* initialize GLUT system */

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(winx, winy);		/* width=500pixels height=500pixels */
	win = glutCreateWindow("Paint Brush");	/* create window */
	glutDisplayFunc(displayScene);		/* set window's display callback */
	glutIdleFunc(displayScene);			/* set window's idle callback */
	glutMouseFunc(mouseB);		/* set window's mouse callback */
	myInit();
	glutMainLoop();			/* start processing events... */
	return 1;

}