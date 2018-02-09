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
    
    bool intersects(Point3D nPE, Point3D pE){
        double b = nPE.dotProduct(center - pE);
        double c = (center - pE).dotProduct((center - pE)) - pow(radius,2);
        
        return b >=0 && pow(b,2)-c>=0; 
    }
    
    double getIntersectionDistance(Point3D nPE, Point3D pE){
        double b = nPE.dotProduct(center - pE);
        double c = (center - pE).dotProduct((center - pE)) - pow(radius,2);
        
        double t = b - sqrt(pow(b,2) -c);
        
        return t;
    }
    
   
    
};

