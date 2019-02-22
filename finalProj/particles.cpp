#include <GL/glut.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <iostream>

class Particle{
private:
  float x, y, vx, vy, r, g, b, rad, mass;
public:
  Particle(int _x, int _y){
    glColor3f(1,1,1);
    x = _x;
    y = _y;
    vx = rand()%(10+1-5)+5;
    vy = rand()%(10+1-5)+5;
    r = g = b = 1.0f;
    rad = 15;
    mass = rad;
    std::cout << "test 2 p const\n";
  }
  void display(void){
    x += vx;
    y += vy;
    glBegin(GL_POLYGON);
    for(int angle=0; angle<40; angle++){
      float radangle = (360/40)*angle*M_PI/180.0;
      glVertex2f(x + rad*cos(radangle), y + rad*sin(radangle));
    }
    glEnd();
    glutSwapBuffers();
  }
  float getMass(){
    return mass;
  }
  float getRad(){return rad;}
  void setVel(float _vx, float _vy){
    vx=_vx;
    vy=_vy;
  }
  float* getVel(){
    float* arr = (float*)malloc(2*sizeof(float));
    arr[0] = vx;
    arr[1] = vy;
    return arr;
  }
  float* getBounds(){
    float* arr = (float*)malloc(4*sizeof(float));
    arr[0] = x-rad;
    arr[1] = x+rad;
    arr[2] = y-rad;
    arr[3] = y+rad;
    return arr;
  }
  float* getPos(){
    float* arr = (float*)malloc(2*sizeof(float));
    arr[0] = x;
    arr[1] = y;
    return arr;
  }
  void collide(Particle* p2){
    float vx1f, vy1f, vx2f, vy2f;
    float mass2 = p2->getMass();
    vx1f = ((mass-mass2)/(mass+mass2))*vx + ((2*mass2)/(mass+mass2))*p2->getVel()[0];
    vy1f = ((mass-mass2)/(mass+mass2))*vy + ((2*mass2)/(mass+mass2))*p2->getVel()[1];
    vx2f = ((2*mass)/(mass+mass2))*vx+((mass2-mass)/(mass+mass2))*p2->getVel()[0];
    vy2f = ((2*mass)/(mass+mass2))*vy+((mass2-mass)/(mass+mass2))*p2->getVel()[1];
    setVel(vx1f, vy2f);
    p2->setVel(vx2f, vy2f);
    display();
    p2->display();
  }
};

class P_system{
private:
  Particle* particles;
  int l, r, b, t, np;
public:
  P_system(int _l, int _r, int _b, int _t, int numParticles){
    l=_l;
    r=_r;
    b=_b;
    t=_t;
    np = numParticles;
    std::cout << "test 1 psys const\n";
    particles = (Particle*)malloc(np*sizeof(Particle));
    for(int i = 0; i<np; i++){
      particles[i] = Particle(rand()%(1260+1-20)+20,rand()%(720+1-20)+20);
    }
  }
  void display(){
    for(int i=0; i<np; i++){
      std::cout << "test 3 b4 getbounds\n";
      float* bounds = particles[i].getBounds();
      std::cout << "test 4 after\n";
      if(bounds[0]<l || bounds[1]>r) particles[i].setVel(-particles[i].getVel()[0], particles[i].getVel()[1]);
      if(bounds[2]<b || bounds[3]>t) particles[i].setVel(particles[i].getVel()[0], -particles[i].getVel()[1]);
      particles[i].display();
      for(int j=0; j<np; j++){
        float* iPos = particles[i].getPos();
        float* jPos = particles[j].getPos();
        float distance = sqrt(pow(jPos[0]-iPos[0],2) + pow(jPos[1]-iPos[1],2));
        if(distance<=particles[i].getRad()+particles[j].getRad()){
          particles[i].collide(&particles[j]);
        }
      }
    }
  }
};

P_system psystem(0, 1280, 0, 720, 5);
void dispSys(){
  while(1){
    glClear(GL_COLOR_BUFFER_BIT);
    psystem.display();
    usleep(20000);
  }
}
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
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Checkerboard");
	init();
  glutDisplayFunc(dispSys);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
