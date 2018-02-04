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

//stolen from http://www.cplusplus.com/forum/beginner/62895/
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



void display(){ //not sure what this does


//    glClearColor( 0, 0, 0, 1 );
//    glClear( GL_COLOR_BUFFER_BIT );
    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, XMAX, YMAX,0.0 );

//    unsigned int pixelColors[XMAX][YMAX][3];
    


    const int M = 4;
    const int N = 4;

    for(int I = 0;  I < XMAX; I++){
        for(int J = 0; J < YMAX; J++){
          //  for(int m = 0; m <  M; m++){
             //   for(int n=0; n < N; n++){
                    double rX = ((double)rand()/(double)RAND_MAX);
                    double rY = ((double)rand()/(double)RAND_MAX);

//                    double X = I + (m + rX)/ M;
//                    double Y = J + (n + rY)/ N;
            
                    double X = I;
                    double Y = J;

                    double x = X / (double) XMAX;
                    double y = Y / (double) YMAX;
                    
//                    int x = X / XMAX;
//                    int y = Y / YMAX;
                    
                    double z = 0;
                    
                    double x00 = 0, y00 = 0, z00 = 0;
                    double a0 = 1;
                    double b0 = 0;
                    double c0 = 0;
                    
                    double a1 = 0;
                    double b1 = 1;
                    double c1 = 0;
                    
                    double s0 = 500;
                    double s1 = 500;
                    
                    double xC = 0;
                    double yC = 0;
                    double zC = 0;
                    
                    double r = 500;

                    double xP = x00 + (a0 * s0 * x) + (a1 * s1 * x);
                    double yP = y00 + (b0 * s0 * y) + (b1 * s1 * y);
                    double zP = z00 + (c0 * s0 * z) + (c1 * s1 * z);

            
            //sphere, go red
                    if(pow(xP - xC, 2) + pow(yP - yC, 2) + pow(zP - zC, 2) - pow(r, 2) <= 0 ){
                      
                        glBegin(GL_POINTS);
                            glColor3f(1,0,0);
//                            glVertex2i(100,100);
                        cout << "(" << X << "," << Y << ")";
                        glVertex2i(X,Y);
                        glEnd();
                    } else {
            //plane, go green
                        
                        int m[4][4] = { {45, 172, 410, (int) xP},
                                        {250, 250, 250, (int) yP},
                                        {76, 391, 3, (int) zP},
                                        {1, 1, 1, 1}};
                        
                        if(determinant(m) == 0 ){
                            glBegin(GL_POINTS);
                            glColor3f(0,1,0);
                            //                            glVertex2i(100,100);
                            cout << "(" << X << "," << Y << ")";
                            glVertex2i(X,Y);
                            glEnd();
                            
                            
                        } else { // cube
                            if( maximum(xP, yP, zP) - 500 <= 0 ){ // should be 125
                                glBegin(GL_POINTS);
                                glColor3f(0,0,1);
                                //                            glVertex2i(100,100);
                                cout << "(" << X << "," << Y << ")";
                                glVertex2i(X,Y);
                                glEnd();
                            } // end if
  
                        } //end cube
                    } //end plane
            
                 


             //   } // end N
            //} // end M
        } // end J
    } //end I


 glFlush();
}

//lifted shamelessy from: http://www.chegg.com/homework-help/questions-and-answers/find-determinant-4x4-matrix-c-q9622213




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

    
//    glutInit( &argc, argv );
//    glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
//    glutInitWindowSize( XMAX, YMAX);
//    glutCreateWindow( "GLUT" );
//    glutDisplayFunc( display );
//    glutMainLoop();
    

   
    
    
    }


