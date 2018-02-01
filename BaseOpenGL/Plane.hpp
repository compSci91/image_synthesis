#include <iostream>
#include <string>
#include <math.h>
#include "Point3D.hpp"

using namespace std;

class Plane {

private:
    Point3D point;
    int a[3][3];
    Point3D n[3];
    Point3D pc= Point3D(0,0,0);
    double s[3];
    
public:
    
    
    Plane(Point3D point){
        this->point = point;
        a[0][2] = 0;
        a[1][2] = 0;
        a[2][2] = 0;
        a[2][1] = 0;
        a[0][0] = 0;
        
        n[0] = Point3D(0.00, 0.71, -0.71);
        n[1] = Point3D(0.94, -0.23, -0.23);
        n[2] = Point3D(0.33, 0.67, 0.67);
        
        s[0] = 5;
        s[1] = 6;
        s[2] = 7;
    }
    
    
    bool F(Point3D p){
    
        double total = 0;
        
        for(int i=0; i<=2; i++){
            total += a[i][2] * pow((n[i].dotProduct(p - pc) / s[i]), 2) + a[2][1]* (n[2].dotProduct(p - pc)) / s[2] + a[0][0];
        }
        
        
        return total <= 0;
            

    }
};
