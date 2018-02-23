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
    
    bool intersects(Vector nPE, Point3D pE){
        double b = nPE.dotProduct(center - pE);
        double c = (center - pE).dotProduct((center - pE)) - pow(radius,2);
        
        return b >=0 && pow(b,2)-c>=0; 
    }
    
    double getIntersectionDistance(Vector nPE, Point3D pE){
        double b = nPE.dotProduct(center - pE);
        double c = (center - pE).dotProduct((center - pE)) - pow(radius,2);
        
        double t = b - sqrt(pow(b,2) -c);
        
        return t;
    }
    
    
    Color calculateDiffuseColor(Point3D lightPoint, Point3D hitPointFromEye, Color lightColor){
        Vector normalVector = (hitPointFromEye - center).produceUnitVector();
        Vector normalizedLightVector = (lightPoint-hitPointFromEye).produceUnitVector();
        return lightColor  * diffuseReflectionCoeffecient * diffuseColor * (normalVector.dotProduct(normalizedLightVector));
    }
    
    Color calculateDiffuseColor(Vector lightVector, Point3D hitPointFromEye, Color lightColor){
        Vector normalVector = (hitPointFromEye - center).produceUnitVector();
        Vector normalizedLightVector = lightVector.produceUnitVector();
        return lightColor  * diffuseReflectionCoeffecient * diffuseColor * (normalVector.dotProduct(normalizedLightVector));
    }
    
    Color calculateSpecularColor(Point3D lightPoint, Point3D hitPoint, Point3D eyePoint, double specularReflectionExponent, Color lightColor){
        Vector normalVector = (hitPoint - center).produceUnitVector();
        Vector normalizedLightVector = (lightPoint-hitPoint).produceUnitVector();
        
        
        Vector reflectionVector = normalizedLightVector - normalVector * 2 * (normalizedLightVector.dotProduct(normalVector));
        
        Vector viewVector = (eyePoint - hitPoint).produceUnitVector(); 
        double cosineOfAngle = reflectionVector.produceUnitVector().dotProduct(viewVector.produceUnitVector());
        
        if(cosineOfAngle < 0 ){ 
            cosineOfAngle = 0;
        }
        
        double specularReflectionFalloff =  pow(cosineOfAngle, specularReflectionExponent);
        
        return lightColor*specularColor*specularReflectionFalloff*specularColorCoefficient*specularReflectionFalloff;
        
    }
    
    Color calculateBorderColor(Point3D eyePoint, Point3D hitPoint){
        Vector normalVector = (hitPoint - center).produceUnitVector();
        Vector normalizedVectorFromEypePointToHitPoint = (hitPoint-eyePoint).produceUnitVector();
        
        double cosineOfAngle = normalVector.dotProduct(normalizedVectorFromEypePointToHitPoint);

        if(cosineOfAngle >= -.15  && cosineOfAngle <= 0.15 ){
            return Color(0, 0, 1);
        }
        
      return Color(0, 0, 0);
    }
    
private:
    double attenuation(Point3D lightPoint, Point3D hitPoint){
        //return 1 / ((pow((lightPoint - hitPoint).calculateMagnitute(), 2) + 1));
        return 1;
    }
    
    
};

