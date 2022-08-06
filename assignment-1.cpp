#include<stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x1,y1,x2,y2,m;
float dx,dy;
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glEnd();
    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glPointSize(5.0);

    if(m<=1)
    {
        while(x1<=x2 && y1<=y2)
        {
            x1=x1+1;
            y1=y1+m;
            glVertex3f(x1,y1,0.0);
            printf("x= %.f y= %.f\n",x1,y1);
        }
    }
    else if(m>1)
    {
        while(x1<=x2 && y1<=y2)
        {
            x1=x1+(1/m);
            y1=y1+1;
            glVertex3f(x1,y1,0.0);
            printf("x= %.f  y= %.f\n",x1,y1);
        }
    }
    glEnd();
    glFlush ();
}
void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv)
{

    printf("Enter value of X1 :");
    scanf("%f",&x1);
    printf("Enter value of y1 :");
    scanf("%f",&y1);
    printf("Enter value of X2 :");
    scanf("%f",&x2);
    printf("Enter value of Y2 :");
    scanf("%f",&y2);
    dx=x2-x1;
    dy=y2-y1;
    m=dy/dx;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
