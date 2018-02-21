#ifndef Plane_hpp
#define Plane_hpp

#include <stdio.h>

#endif /* Plane_hpp */

#include "Color.hpp"

class Plane {
    
private:
    Point3D point;
    Vector directionVector;
    double diffuseReflectionCoeffecient, specularColorCoefficient;
    Color diffuseColor;
    Color specularColor;
    
public:
    Plane(Point3D point, Vector directionVector){
        this-> point = point;
        this->directionVector = directionVector.produceUnitVector();
        
        this -> specularColor = Color(1, 1, 1);
        this -> diffuseColor = Color(0, 1, 0);

        
        this -> diffuseReflectionCoeffecient = 1;
        this -> specularColorCoefficient = 1;
    }
    
    
    bool intersects(Vector nPE, Point3D pE){
        
        
        double denominator = nPE.dotProduct(directionVector);
        if(denominator == 0){
            return false;
        }
        
        double t = (point - pE).dotProduct(directionVector) / denominator;
        
        return t >=0;
    }
    
    double getIntersectionDistance(Vector nPE, Point3D pE){
        double denominator = nPE.dotProduct(directionVector);
        
        double t = (point - pE).dotProduct(directionVector) / denominator;
        
        return t;
    }
    
    Color calculateDiffuseColor(Point3D lightPoint, Point3D hitPoint, Color lightColor){
        Vector normalVector = directionVector.produceUnitVector();
        Vector normalizedLightPointVector = (lightPoint-hitPoint).produceUnitVector();
        // return lightColor*diffuseColor*diffuseReflectionCoeffecient*attenuation(lightPoint, hitPoint);
        return lightColor * diffuseReflectionCoeffecient * this->diffuseColor * (normalVector.dotProduct(normalizedLightPointVector)) * attenuation(lightPoint, hitPoint);
    }

private:
    double attenuation(Point3D lightPoint, Point3D hitPoint){
        double magnitude = ((lightPoint - hitPoint).calculateMagnitute());
        double attenuation = 300 / magnitude;

        return attenuation;
    }
};
