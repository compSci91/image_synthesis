/*
    Example for how to handle header files and cpp files, should I 
 */
#include <OpenGL/gl.h>
#include "Point3D.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include <GLUT/glut.h>
#include <iostream>


const unsigned int XMAX = 500;
const unsigned int YMAX = 500;

//lifted shamelessy from: http://www.chegg.com/homework-help/questions-and-answers/find-determinant-4x4-matrix-c-q9622213

double determinant(int m[4][4]) {
    return
    m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
    m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
    m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
    m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
    m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
    m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
    m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
    m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
    m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
    m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
    m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
    m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3];
}

//citation:  from http://www.cplusplus.com/forum/beginner/62895/
double maximum (double a,double b,double c)
{
    if(a>b)
    {
        if(a>c)
        {    return a;
        }
        else if(b>a)
        {
            if(b>c)
            {
                return b;
            }
        }
        else if(c>b)
        {
            if(c>a)
            {
                return c;
            }
        }
    }
    
    return INT_MAX;
}

double minimum (double a,double b,double c)
{
    if(a<b)
    {
        if(a<c)
        {    return a;
        }
        else if(b<a)
        {
            if(b<c)
            {
                return b;
            }
        }
        else if(c<b)
        {
            if(c<a)
            {
                return c;
            }
        }
    }
    
    return INT_MIN;
}

double absoluteValue(double a){
    if(a<0){
        a = -1 * a;
    }
    
    return a;
}

void display(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, XMAX, YMAX,0.0 );

    
    //    Point3D pE = Point3D(250, 250, 250);
    Point3D pE = Point3D(0, 250, 250);
   // Point3D vView = Point3D(0, 0, -250);
    Point3D vView = Point3D(250, 0, -250);
    Point3D n2 = vView.produceUnitVector();
    
    Point3D vUp = Point3D(0, 1, 0);
    Point3D n0 = n2*vUp;
    
    Point3D n1 = n0 * n2;
    
   
    double d = 250;
    Point3D pC = pE + n2 * d;
    
    Point3D p00 = pC - (n0*(XMAX/2) + n1*(YMAX/2));
   // Point3D p00 = Point3D(0, 250, 0);

    const int M = 2;
    const int N = 2;

    for(int I = 0;  I < XMAX; I++){
        for(int J = 0; J < YMAX; J++){
            
            float red = 0, green=0, blue=0;
            for(int m = 0; m <  M; m++){
                for(int n=0; n < N; n++){
                    
                    //STEP 1: FOR EVERY POINT IN THE DISPLAY, FIND THE CORRESPONDING
                    // POINT IN THREE DIMENSIONAL SPACE
                    double rX = ((double)rand()/(double)RAND_MAX);
                    double rY = ((double)rand()/(double)RAND_MAX);

                    double X = I + (m + rX)/ M;
                    double Y = J + (n + rY)/ N;
        

                    double x = X / (double) XMAX;
                    double y = Y / (double) YMAX;
                
                    
                    
                    
                    //STEP 2:
                    double s0 = 500;
                    double s1 = 500;
                    
                    
                    Point3D centerOfSphere = Point3D(250, 250, 0);
                    Point3D pP = p00 + n0*(s0 * x) + n1*(s1 * y);
                    
                    
                    Point3D nPE = (pP - pE).produceUnitVector(); 
                    
                    
                    
                    
                    Sphere sphere = Sphere(centerOfSphere, 125);
                    Plane plane = Plane(Point3D(250, 375, 0), Point3D(0, 1/sqrt(2), 1/sqrt(2)));
            
            //sphere, go red
//                    if(sphere.contains(pP) ){
//                        red++;
//                    }
                    
                   
                    bool sphereIntersects = sphere.intersects(nPE, pE);
                    bool planeIntersects = plane.intersects(nPE, pE);
                    
                    if(sphereIntersects && !planeIntersects){
                        red++;
                    } else if(planeIntersects && !sphereIntersects) {
                        green++;
                    } else if(sphereIntersects && planeIntersects){
                        double sphereIntersectionDistance = sphere.getIntersectionDistance(nPE, pE);
                        double planeIntersectionDistance = plane.getIntersectionDistance(nPE, pE);


                        
                        if(sphereIntersectionDistance <= planeIntersectionDistance){
                            red++;
                            
                        } else if( planeIntersectionDistance < sphereIntersectionDistance) {
                            green++;
                        }
                    }
                } // end N
            } // end M
            
            glBegin(GL_POINTS);
                glColor3f(red/4.0,green/4.0,blue/4.0);
                glVertex2i(I,YMAX-J);
            glEnd();
        } // end J
    } //end I


 glFlush();
}







int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(XMAX, YMAX);
    glutInitWindowPosition(XMAX, YMAX); // Will need to look this up
    glutCreateWindow("Sphere");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;

    }


