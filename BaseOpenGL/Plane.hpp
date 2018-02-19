#ifndef Plane_hpp
#define Plane_hpp

#include <stdio.h>

#endif /* Plane_hpp */

#include "Color.hpp"

class Plane {
    
private:
    Point3D point;
    Point3D directionVector;
    double diffuseReflectionCoeffecient, specularColorCoefficient;
    Color diffuseColor;
    Color specularColor;
    
public:
    Plane(Point3D point, Point3D directionVector){
        this-> point = point;
        this->directionVector = directionVector.produceUnitVector();
        
        this -> specularColor = Color(1, 1, 1);
        this -> diffuseColor = Color(0, 1, 0);

        
        this -> diffuseReflectionCoeffecient = 1;
        this -> specularColorCoefficient = 1;
    }
    
    
    bool intersects(Point3D nPE, Point3D pE){
        
        
        double denominator = nPE.dotProduct(directionVector);
        if(denominator == 0){
            return false;
        }
        
        double t = (point - pE).dotProduct(directionVector) / denominator;
        
        return t >=0;
    }
    
    double getIntersectionDistance(Point3D nPE, Point3D pE){
        double denominator = nPE.dotProduct(directionVector);
        
        double t = (point - pE).dotProduct(directionVector) / denominator;
        
        return t;
    }
    
    Color calculateDiffuseColor(Point3D lightPoint, Point3D hitPoint, Color lightColor){
        Point3D normalVector = directionVector.produceUnitVector();
        Point3D normalizedLightPoint = lightPoint.produceUnitVector();
        // return lightColor*diffuseColor*diffuseReflectionCoeffecient*attenuation(lightPoint, hitPoint);
        return lightColor * attenuation(lightPoint, hitPoint) * diffuseReflectionCoeffecient * diffuseColor * (normalVector.dotProduct(normalizedLightPoint));
    }
    
private:
    double attenuation(Point3D lightPoint, Point3D hitPoint){
//        double attenuation = 1 / ((pow((lightPoint - hitPoint).calculateMagnitute(), 1) + 1));
//        cout << "Attenuation: " << attenuation << endl;
//
//        return attenuation;
        
       double magnitude = ((lightPoint - hitPoint).calculateMagnitute());
        double attenuation = 300 / magnitude;
//        cout << "Magnitude: " << magnitude << endl;
//        cout << "Attenuation: " << attenuation << endl << endl;
        
                return attenuation;
        return 1;
    }
};
