#include <GL/glut.h>

int gsize = 0;

void checkerboard(void){
  glClear(GL_COLOR_BUFFER_BIT);
  bool white = 1;
  for(int r=0; r<8; r++){
    for(int c=0; c<8; c++){
      if(white){
        glColor3f(1.0,1.0,1.0);
      }
      else{
        glColor3f(0.0,0.0,0.0);
      }
      glBegin(GL_POLYGON);
      glVertex3i(r*gsize, c*gsize, 0);
      glVertex3i(r*gsize+gsize, c*gsize, 0);
      glVertex3i(r*gsize+gsize, c*gsize+gsize, 0);
      glVertex3i(r*gsize, c*gsize+gsize, 0);
      glEnd();
      glFlush();
      white = !white;
    }
  }
}

void init(void)
{
	/* select clearing color 	*/
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/* initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}


int main(int argc, char** argv){
  gsize = 100;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(8*gsize, 8*gsize);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Checkerboard");
	init();
	glutDisplayFunc(checkerboard);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
