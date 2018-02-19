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

    
    Point3D pE = Point3D(250, 250, 250);
    Point3D pL = Point3D(250, 500, 250);
    
    Point3D vView = Point3D(0, 0, -250);
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
            
            Color colorForPixel = Color(0, 0, 0);
            
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
                    Point3D nLE = (pP - pL).produceUnitVector();
                    
                    Sphere sphere = Sphere(centerOfSphere, 125);
 
                   
                    bool sphereIntersectsWithEyeVector = sphere.intersects(nPE, pE);
                    
                    if(sphereIntersectsWithEyeVector) {
                        double t = sphere.getIntersectionDistance(nPE, pE);
                        Point3D hitPointFromEye = pE + nPE * t;
                        Color whiteColor = Color(1,1,1);
                        Color diffuseColorFromSphere = sphere.calculateDiffuseColor(pE, hitPointFromEye, whiteColor);
                       
                        colorForPixel = colorForPixel + diffuseColorFromSphere;
                        
                        //need to calculate specular color
                    }
                    
                    bool sphereIntersectsWithLightVector = sphere.intersects(nLE, pL);
                    
                    if(sphereIntersectsWithLightVector){
                        double t = sphere.getIntersectionDistance(nLE, pL);
                        Point3D hitPointFromLight = pL + nLE * t;
                        Color whiteColor = Color(1,1,1);
                        double specularReflectionExponent = 100;
                        Color specularColorFromSphere = sphere.calculateSpecularColor(pL, hitPointFromLight, pE, specularReflectionExponent, whiteColor);
                        
                        colorForPixel = colorForPixel + specularColorFromSphere;
                    }
                    

                    
                    

                } // end N
            } // end M
            
            glBegin(GL_POINTS);
            glColor3f(colorForPixel.red/4.0,colorForPixel.green/4.0,colorForPixel.blue/4.0);
                glVertex2i(I,YMAX-J);
            glEnd();
        } // end J
    } //end I


 glFlush();
}


Point3D F(Point3D p, Point3D pC, int a[3][3], int s[2], Point3D n[3] ){
    Point3D finalPoint = Point3D(0, 0, 0);
    
    for(int i = 0; i <=2; i++){
        
        finalPoint = finalPoint + n[i]*(2*a[i][2]*n[i].dotProduct(p - pC) / pow(s[i], 2)) + n[2]*(a[2][1]/s[2]);
    }
    
    return finalPoint;
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
    
//    Point3D pH = Point3D(5,16.01,7.95);
//    Point3D pC = Point3D(5,8,12);
//    int a[3][3] = {{-1, 0, 1}, {0, 0, 1}, {0, 0, 1}};
//
//    cout << a[2][0] << endl;
//    int s[3] = {9, 5, 3};
//
//    Point3D n[3] = {Point3D(0.00,0.89,-0.45), Point3D(0.96,-0.13,-0.26), Point3D(0.29,0.43,0.86)};
//
//    Point3D returnedPoint = F(pH, pC, a, s, n).produceUnitVector();
//
//    returnedPoint.print();
    return 0;

    }


