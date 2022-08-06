
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
int x1,y1,r;


void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x+x1, y+y1);
    glEnd();
}

void init(void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f,0.0f,0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
}

void midPointCircle()
{
    int x=0;
    int y=r;
    float d = 5/4 -r;
    plot(x,y);
    while(y>x){
        if(d<0){
            x++;
            d+=2*x+1;
        }
        else{
                y--;
            x++;
            d+=2*(x-y)+1;
        }
        plot(x,y);
        plot(x,-y);
        plot(-x,y);
        plot(-x,-y);
        plot(y,x);
        plot(-y,x);
        plot(y,-x);
        plot(-y,-x);

    }

}
void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0);
    glPointSize(4.0);
    midPointCircle();
    glFlush();

}

int main(int argc, char** argv)
{
    cout<<"x= "; cin>>x1;
    cout<<"y= "; cin>>y1;
    cout<<"r= "; cin>>r;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("hello");
    glutDisplayFunc(myDisplay);
    init ();
    glutMainLoop();
    return 0;
}
