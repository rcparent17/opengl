#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <iostream>

float t = 0.0;
float inc = 1.0/60.0;
float direction = 1.0;

float lerp(float a, float b, float t)
{
  return a + (b - a) * t;
}

void tween(void){
  if(t>=1.0) direction = -1.0;
  if(t<=0.0) direction = 1.0;
    glBegin(GL_LINE_STRIP);
    glVertex2f(lerp(0, 300, t), 300);
    glVertex2f(300, lerp(300, 600, t));
    glVertex2f(lerp(600, 300, t), 300);
    glVertex2f(300, lerp(300, 0, t));
    glVertex2f(lerp(0, 300, t), 300);
    glEnd();
    glutSwapBuffers();
    glClear(GL_COLOR_BUFFER_BIT);
    t+=(direction*inc);
    usleep(400000);
  }

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tween");
  glMatrixMode(GL_PROJECTION);
	glClearColor(0.0, 0.0, 0.0, 1.0);
  gluOrtho2D(0, 600, 0, 600);
  
	glutDisplayFunc(tween);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
