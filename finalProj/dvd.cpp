#include <GL/glut.h>
#include <time.h>

class Particle{
private:
  float x, y, vx, vy, r, g, b, rad, mass;
public:
  construct(int _x, int _y){
    glColor3f(1,1,1);
    x = xx;
    y = yy;
    vx = vy = 0.2;
    r = g = b = 1.0f;
    rad = 3;
    mass = rad
  }
  void display(){
    glBegin(GL_POLYGON);
    for(int angle=0; angle<20; angle++){
      float radangle = (360/20)*angle*M_PI/180.0;
      glVertex2f(x + rad*cos(radangle), y + rad*sin(radangle));
    }
    glFlush();
    glEnd();
  }
  void update(){
    x += vx;
    y += vy;
    glutDisplayFunc(display);
  }
  float getMass(){
    return mass;
  }
  void setVel(float _vx, float _vy){
    vx=_vx;
    vy=_vy;
  }
  float[] getVel(){
    return {vx, vy};
  }
  void collide(Particle* p2){
    float vx1f, vy1f, vx2f, vy2f;
    float mass2 = p2.getMass();
    vx1f = ((mass-mass2)/(mass+mass2))*vx + ((2*mass2)/(mass+mass2))*p2.getVel()[0];
    vy1f = ((mass-mass2)/(mass+mass2))*vy + ((2*mass2)/(mass+mass2))*p2.getVel()[1];
    vx2f = ((2*mass)/(mass+mass2))*vx+((mass2-mass)/(mass+mass2))*p2.getVel()[0];
    vy2f = ((2*mass)/(mass+mass2))*vy+((mass2-mass)/(mass+mass2))*p2.getVel()[1];
    setVel(vx1f, vy2f);
    p2.setVel(vx2f, vy2f);
    update();
    p2.update();
  }
};

class System{
private:
  Particle particles[2];
public:
  construct(){
    particles[0] = new Particle(10,10);
    particles[1] = new Particle(10,1270);
  }
  void update(){
    
  }
};

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1280, 0.0, 720, 0.0, 1.0);
}

int main(int argc, char** argv){
  srand(time(NULL));
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Checkerboard");
	init();

	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
