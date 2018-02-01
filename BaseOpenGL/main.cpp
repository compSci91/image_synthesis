/*
    Example for how to handle header files and cpp files, should I 
 */
#include <OpenGL/gl.h>
#include "Point3D.hpp"
#include <GLUT/glut.h>

//void displayMe(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//    glBegin(GL_POLYGON);
//    glVertex3f(0.0, 0.0, 0.0);
//    glVertex3f(0.5, 0.0, 0.0);
//    glVertex3f(0.5, 0.5, 0.0);
//    glVertex3f(0.0, 0.5, 0.0);
//    glEnd();
//    glFlush();
//}

int main(int argc, char** argv)
{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE);
//    glutInitWindowSize(300, 300);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Hello world :D");
//    glutDisplayFunc(displayMe);
//    glutMainLoop();
    
    Point3D point1(1,2,3);
    Point3D point2(3, 4, 5);
    Point3D point3 = point1 - point2;
    double dotProduct = point1.dotProduct(point2);
    Point3D point5 = point1 * 3;
    
    point3.print();
    cout << "The double product is: " << dotProduct << endl; 
    point5.print();
    return 0;
}


