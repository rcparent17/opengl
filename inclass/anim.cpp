#include <GL/glut.h>
#include <unistd.h>

int w = 0;
int h = 0;

void init(void){
  /* select clearing color 	*/
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/* initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 700.0, 0.0, 700.0, 0.0, 1.0);
}

void square(void){
  for(int i = 0; i<1000000; i++){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glRecti(0,0, w++, h++);
    usleep(50000);
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Checkerboard");
	init();
  glutDisplayFunc(square);
  glutMainLoop();
  return 0;
}
