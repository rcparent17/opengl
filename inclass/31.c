#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

void myDisplay(void)
{
        glBegin(GL_LINE_STRIP);
   for(GLfloat x = -4.0; x < 4.0; x += 0.1)
        {
                GLfloat y = sin(3.14159 * x) / (3.14159 * x);
                glVertex2f(x, y);
        }
        glEnd();
        glFlush();
}

void init(void)
{
        glClearColor(0.0,0.0,0.0,0.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-4.0, 4.0, -2.0, 2.0, -1.0, 1.0);
}

int main(int argc, char** argv) 
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(1000, 1000);
        glutCreateWindow("3.1");
        init();
        for(int i=0; i <5; i++){
          for(int j=0; j<5; j++){

          }
        }
        glutDisplayFunc(myDisplay);
        glutMainLoop();

        return 0;
}
