#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <fstream>

using namespace std;
void drawPolyLineFile(char * fileName)
{
	fstream inStream;
	inStream.open(fileName, ios ::in);	// open the file
	if(inStream.fail())
		return;
	//glClear(GL_COLOR_BUFFER_BIT);      // clear the screen
	GLint numpolys, numLines, x ,y;
	inStream >> numpolys;		           // read the number of polylines
	for(int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

int main(void){
  gluOrtho2D(0, 640.0, 0, 440.0);
  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      glViewport(i*64, j*44, 64,44);
      drawPolyLineFile("dino.dat");
    }
  }
  return 0;
}
