#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <unistd.h>

GLdouble eyex = 2.3;
GLdouble eyey = 1.3;
GLdouble eyez = 2.0;
GLdouble centerx = 0.0;
GLdouble centery = 0.25;
GLdouble centerz = 0.0;
GLdouble upx = 0.0;
GLdouble upy = 0.5;
GLdouble upz = 0.0;

void displaySolid(void)
{
  //set properties of the surface material
  GLfloat mat_amb[] = {0.4, 0.4, 1.0, 0.0};
  GLfloat mat_diff[] = {0.6, 0.6, 0.6, 0.0};
  GLfloat mat_spec[] = {0.0, 0.0, 0.0, 0.0};
  GLfloat mat_shin[] = {100.0};
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_amb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diff);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shin);
  //set the light source properties
  GLfloat lightInt[] = {1, 0, 0, 0.0};
  GLfloat light_pos[] = {2.0, 6.0, 3.0, 0.0};
  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightInt);

  //set the camera
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-64/48.0, 64/48.0, -1, 1, -100.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz);

  glPushMatrix();
  glScaled(0.08, 0.08, 0.08);
  glPopMatrix();
  glPushMatrix();
  glTranslated(.6, .38, .5);
  int timer = 0;
  while(1){
    if(++timer<50){
      glScaled(1.01,1.01,1.01);
    }
    else{
      glScaled(.99,.99,.99);
    }
    if(timer>25&&timer<50) glTranslated(.01, 0, 0);
    if(timer>75&&timer<100) glTranslated(-.01, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glRotated(1, 0, 1, 0);
    glutSolidTeapot(0.3);
    glPushMatrix();
    glPopMatrix();
    glFlush();
    if(timer>=100) timer=0;
    usleep(20000);
  }


}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Moving Teapot");
  glutDisplayFunc(displaySolid);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glClearColor(.2, 0, 0.3, 0.0); //purple
  glViewport(0, 0, 640, 480);
  glutMainLoop();
}
