/*
    Example for how to handle header files and cpp files, should I 
 */
#include <OpenGL/gl.h>
#include "Point3D.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Vector.hpp"
#include <GLUT/glut.h>
#include <iostream>
#include <stdio.h>
#include <SOIL.h>



const unsigned int XMAX = 500;
const unsigned int YMAX = 500;


void display(){
    
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D( 0.0, XMAX, YMAX,0.0 );
    
    Point3D centerOfSphere = Point3D(275, 10, 100);
    Sphere sphere = Sphere(centerOfSphere, 5);
    Plane plane = Plane(Point3D(0, 0, 0), Vector(0, 1 , 0));

    Point3D pE = Point3D(270, 5, 125);
    Point3D pL = Point3D(0, 200, 100);
    Vector lightVector = Vector(0, 1, 0);
    
    Vector spotDirection = (centerOfSphere - pL).produceUnitVector();
    double cutoffAngle = 3 * 3.14159265 / 180;
    
    Point3D specularPL = Point3D(400, 400, 250);
    
    Vector vView = Vector(0, 0, -250);
    Vector n2 = vView.produceUnitVector();

    Vector vUp = Vector(0, 1, 0);
    Vector n0 = n2*vUp;

    Vector n1 = n0 * n2;
    
    double magnitude = 250;
    Point3D pC = pE + (n2 * magnitude);
    
    Point3D p00 = pC - (n0*(XMAX/2) + n1*(YMAX/2));
    
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
                 
                    Point3D pP = p00 + n0*(s0 * x) + n1*(s1 * y);
                    Vector nPE = (pP - pE).produceUnitVector();
                    
                    bool sphereIntersectsWithEyeVector = sphere.intersects(nPE, pE);
        
                    if(sphereIntersectsWithEyeVector) {
                        double t = sphere.getIntersectionDistance(nPE, pE);
                        Point3D hitPointFromEye = pE + nPE * t;
                        
                        
                
                        Color whiteColor = Color(1,1,1);
                        Color diffuseColorFromSphere = sphere.calculateDiffuseColor(pL, hitPointFromEye, whiteColor);

                        colorForPixel = colorForPixel + diffuseColorFromSphere;
                        
                    } // end SphereIntersectsWithEyeVector
                } // end N
            } // end M
            
            glBegin(GL_POINTS);
            glColor3f(colorForPixel.red/(M*N),colorForPixel.green/(M*N),colorForPixel.blue/(M*N));
                glVertex2i(I,YMAX-J);
            glEnd();
        } // end J
    } //end I


 glFlush();
}


//Point3D F(Point3D p, Point3D pC, int a[3][3], int s[2], Point3D n[3] ){
//    Point3D finalPoint = Point3D(0, 0, 0);
//
//    for(int i = 0; i <=2; i++){
//
//        finalPoint = finalPoint + n[i]*(2*a[i][2]*n[i].dotProduct(p - pC) / pow(s[i], 2)) + n[2]*(a[2][1]/s[2]);
//    }
//
//    return finalPoint;
//}

//Stolen From: https://stackoverflow.com/questions/9296059/read-pixel-value-in-bmp-file
//Just so I could make progress

/*
 Now data should contain the (R, G, B) values of the pixels.
 The color of pixel (i, j) is stored at
 data[3 * (i * width + j)],
 data[3 * (i * width + j) + 1] and
 data[3 * (i * width + j) + 2].
 
 */
unsigned char* readBMP(string filename)
{
    int i;
    FILE* f = fopen(filename.c_str(), "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header
    
    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    
    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    fclose(f);
    
   // In the last part, the swap between every first and third pixel is done because windows stores the color values as (B, G, R) triples, not (R, G, B).

    for(i = 0; i < size; i += 3)
    {
        unsigned char tmp = data[i];
        data[i] = data[i+2];
        data[i+2] = tmp;
    }
    
    return data;
}




int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(XMAX, YMAX);
    glutInitWindowPosition(XMAX, YMAX); // Will need to look this up
    glutCreateWindow("Sphere");
    glutDisplayFunc(display);
    glutMainLoop();

   
    
    return 0;
}
