#include <GL/glut.h>

int checkerSize = 0;
int diamondX = 0;
int diamondY = 0;
int diamondR = 0;

void checkerboard(void){
  int offset = 0;
  glClear(GL_COLOR_BUFFER_BIT);

  for(int r=0; r<8; r++){
    for(int c=0; c<8; c++){
      if(r%2){
        offset = checkerSize;
      }
      else{
        offset = 0;
      }
      glColor3f(1.0,1.0,1.0);
      glRecti(r*checkerSize,offset+2*c*checkerSize,r*checkerSize+checkerSize, offset+2*c*checkerSize+checkerSize);
      glFlush();
    }
  }
}

void diamond(void){
  for(int i = 0; i<100; i++){
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2i(diamondX-diamondR, diamondY);
    glVertex2i(diamondX, diamondY+diamondR);
    glVertex2i(diamondX+diamondR, diamondY);
    glVertex2i(diamondX, diamondY-diamondR);
    glEnd();
    glFlush();
    diamondX = (rand() % (8*checkerSize + 1));
    diamondY = (rand() % (8*checkerSize + 1));
    diamondR = (rand() % (40 - 20 + 1)) + 20;
  }
}

void diamond(int x, int y, int size){
  diamondX = x;
  diamondY = y;
  diamondR = size;
  glutDisplayFunc(diamond);
}

void init(int size)
{
	/* select clearing color 	*/
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/* initialize viewing values  */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 8*size, 0.0, 8*size, 0.0, 1.0);
  //glTranslatef(-4.0*checkerSize,-4.0*checkerSize, 0.0);
}

void checkerboard(int size){
  checkerSize = size;
  glutDisplayFunc(checkerboard);
}

int main(int argc, char** argv){
  int size = 100;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(8*size, 8*size);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Checkerboard");
	init(size);
	checkerboard(size);
  diamond(4*size, 4*size, 50);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
