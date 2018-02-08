#ifndef Plane_hpp
#define Plane_hpp

#include <stdio.h>

#endif /* Plane_hpp */

class Plane {
    
private:
    Point3D point;
    Point3D directionVector;
    
public:
    Plane(Point3D point, Point3D directionVector){
        this-> point = point;
        this->directionVector = directionVector;
    }
    
    
    bool intersects(Point3D nPE, Point3D pE){
        
        
        double denominator = nPE.dotProduct(directionVector);
        if(denominator == 0){
            return false;
        }
        
        double t = (point - pE).dotProduct(directionVector) / denominator;
        
        return t >=0;
    }
};
