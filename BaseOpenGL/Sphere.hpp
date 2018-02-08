#ifndef Sphere_hpp
#define Sphere_hpp

#include <stdio.h>

#endif /* Sphere_hpp */

#include <math.h>

class Sphere {
private:
    Point3D center;
    double radius;
    
    
public:
    Sphere(Point3D center, double radius){
        this -> center = center;
        this -> radius = radius;
    }
    
    bool contains(Point3D point){
        return (point - center).dotProduct((point - center)) - pow(radius,2) <= 0;
    }
    
};

