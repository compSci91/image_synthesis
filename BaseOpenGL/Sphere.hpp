#ifndef Sphere_hpp
#define Sphere_hpp

#include <stdio.h>

#endif /* Sphere_hpp */

#include <math.h>
#include "Color.hpp"

class Sphere {
private:
    Point3D center;
    double radius;
    double diffuseReflectionCoeffecient;
    Color diffuseColor; 
    
    
public:
    Sphere(Point3D center, double radius){
        this -> center = center;
        this -> radius = radius;
        this -> diffuseColor = Color(1, 0, 0);
        this -> diffuseReflectionCoeffecient = 1;
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
    
    
    Color calculateDiffuseColor(Point3D lightPoint, Point3D hitPoint, Color lightColor){
        Point3D normalVector = (hitPoint - center).produceUnitVector();
        Point3D normalizedLightPoint = lightPoint.produceUnitVector();
       // return lightColor*diffuseColor*diffuseReflectionCoeffecient*attenuation(lightPoint, hitPoint);
        return lightColor * attenuation(lightPoint, hitPoint) * diffuseReflectionCoeffecient * diffuseColor * (normalVector.dotProduct(normalizedLightPoint));
    }
    
private:
    double attenuation(Point3D lightPoint, Point3D hitPoint){
        //return 1 / ((pow((lightPoint - hitPoint).calculateMagnitute(), 2) + 1));
        return 1;
    }
    
    
};

