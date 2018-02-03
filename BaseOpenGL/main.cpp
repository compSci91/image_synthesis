/*
    Example for how to handle header files and cpp files, should I 
 */
#include <OpenGL/gl.h>
#include "Point3D.hpp"
#include <math.h>
#include <GLUT/glut.h>

const unsigned int XMAX = 300;
const unsigned int YMAX = 300;

void displayMe(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, XMAX, YMAX,0.0 );
    
    glBegin(GL_POINTS);
        glColor3f(1,0,0);
        glVertex2i(100,100);
    glEnd();
    
    glBegin(GL_POINTS);
        glColor3f(0,1,0);
        glVertex2i(200,100);
    glEnd();
    glFlush();

}


//void display(){ //not sure what this does
//
//
//    glClearColor( 0, 0, 0, 1 );
//    glClear( GL_COLOR_BUFFER_BIT );
//
//    unsigned int pixelColors[XMAX][YMAX][3];
//
//    const int M = 4;
//    const int N = 4;
//
//    for(int I = 0;  I < XMAX; I++){
//        for(int J = 0; J < YMAX; J++){
//            for(int m = 0; m <  M; m++){
//                for(int n=0; n < N; n++){
//                    double rX = ((double)rand()/(double)RAND_MAX);
//                    double rY = ((double)rand()/(double)RAND_MAX);
//
//                    double X = I + (m + rX)/ M;
//                    double Y = J + (n + rY)/ N;
//
//                    double x = X / (double) XMAX;
//                    double y = Y / (double) YMAX;
//
//                    double xP = x00 + (a0 * s0 * x) + (a1 * s1 * x);
//                    double yP = y00 + (b0 * s0 * y) + (b1 * s1 * y);
//                    double zP = z00 + (c0 * s0 * z) + (c1 * s1 * z);
//
//                    if(pow(xP - xC, 2) + pow(yP - yC, 2) + pow(zP - zC, 2) - pow(r, 2) <= 0 ){
//                        //make the point red
//                        pixelColors[y][x][0] = 255;
//                        pixelColors[y][x][1] = 0;
//                        pixelColors[y][x][2] = 0;
//                    } else {
//                        //make the point green
//                        pixelColors[y][x][0] = 0;
//                        pixelColors[y][x][1] = 255;
//                        pixelColors[y][x][2] = 0;
//                    }
//
//
//                }
//            }
//        }
//    }
//
//    glDrawPixels(XMAX, YMAX, GL_RGB, GL_UNSIGNED_INT, pixelColors );
//
//    glutSwapBuffers();
//}

void testDisplay(){
    
}

int main(int argc, char** argv)
{
    
   
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(XMAX, YMAX);
    glutInitWindowPosition(XMAX, YMAX); // Will need to look this up
    glutCreateWindow("Sphere");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;

    
//    glutInit( &argc, argv );
//    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
//    glutInitWindowSize( XMAX, YMAX);
//    glutCreateWindow( "GLUT" );
//    glutDisplayFunc( display );
//    glutMainLoop();
    

   
    
    
    
    return 0;
}


