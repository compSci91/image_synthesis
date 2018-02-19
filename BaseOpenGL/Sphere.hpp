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
    double diffuseReflectionCoeffecient, specularColorCoefficient;
    Color diffuseColor;
    Color specularColor;
    
    
public:
    Sphere(Point3D center, double radius){
        this -> center = center;
        this -> radius = radius;
        this -> diffuseColor = Color(1, 0, 0);
        this -> specularColor = Color(1, 1, 1);
        
        this -> diffuseReflectionCoeffecient = 1;
        this -> specularColorCoefficient = 1;
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
    
    Color calculateSpecularColor(Point3D lightVector, Point3D hitPoint, Point3D viewVector, double specularReflectionExponent, Color lightColor){
         Point3D normalVector = (hitPoint - center).produceUnitVector();
        Point3D reflectionVector = normalVector* 2*(lightVector.dotProduct(normalVector)) - lightVector;
        
        double cosineOfAngle = reflectionVector.produceUnitVector().dotProduct(viewVector.produceUnitVector());
        
        if(cosineOfAngle < 0 ){ 
            cosineOfAngle = 0;
        }
        
        double specularReflectionFalloff =  pow(cosineOfAngle, specularReflectionExponent);
        
        return lightColor*specularColor*specularReflectionFalloff*specularColorCoefficient*specularReflectionFalloff;
        
    }
    
private:
    double attenuation(Point3D lightPoint, Point3D hitPoint){
        //return 1 / ((pow((lightPoint - hitPoint).calculateMagnitute(), 2) + 1));
        return 1;
    }
    
    
};

