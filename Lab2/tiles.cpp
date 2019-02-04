#include <GL/glut.h>
#include <math.h>
#include <time.h>

int size = 1000;

void setWindow(float left, float right, float bottom, float top){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void draw_arc(float px, float py, int arcstart, int arcend, int h, int w){
	float x, y;
	glColor3f(1, 1, 1);
	glBegin(GL_LINE_STRIP);
	for (int t = arcstart; t <= arcend; t++) {
		x = h * sin(t * M_PI / 180) + px;
		y = w * cos(t * M_PI / 180) + py;
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void tile1(void){
	int tSize = size/5;
	int arcSize = tSize/2;
	setWindow(0.0, (float)size, 0.0, (float)size);
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			glViewport(i*tSize, j*tSize, size, size);
			draw_arc(0,0,0,90,arcSize,arcSize);
			draw_arc(tSize,0, 270, 360, arcSize, arcSize);
			draw_arc(0,tSize,90,180,arcSize,arcSize);
			draw_arc(tSize,tSize, 180, 270, arcSize, arcSize);
		}
	}
}

void truchet(){
	int tSize = size/10;
	int arcSize = tSize/2;
	setWindow(0.0, (float)size, 0.0, (float)size);
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if((int)(rand()%2)){
				glViewport(i*tSize, j*tSize, size, size);
				draw_arc(0,0,0,90,arcSize,arcSize);
				draw_arc(tSize,tSize, 180, 270, arcSize, arcSize);
			}
			else{
				glViewport(i*tSize, j*tSize, size, size);
				draw_arc(tSize,0,270,360,arcSize,arcSize);
				draw_arc(0,tSize, 90, 180, arcSize, arcSize);
			}

		}
	}
}

void tile2(void){
	int tSize = size/5;
	setWindow(0.0, (float)size, 0.0, (float)size);
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			glViewport(i*tSize, j*tSize, size, size);
			draw_arc(0,0,0,90,tSize,tSize);
			draw_arc(tSize,tSize, 180, 270, tSize, tSize);
			draw_arc(0,tSize,90,180,tSize,tSize);
			draw_arc(tSize,0, 270, 360, tSize, tSize);
		}
	}
}

int main(int argc, char** argv){
	srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(size, size);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tiles");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	//glutDisplayFunc(tile1);
	//glutDisplayFunc(tile2);
	//glutDisplayFunc(truchet);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
