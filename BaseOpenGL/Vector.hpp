//
//  Vector.hpp
//  BaseOpenGL
//
//  Created by Joshua Howell on 2/21/18.
//  Copyright © 2018 Joshua Howell. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>
#include <cmath>

#pragma once
#endif /* Vector_hpp */

class Vector {
public:
    double x, y, z;
    
    Vector (){
        
    }
    
    Vector(double x, double y, double z){
        this -> x = x;
        this -> y = y;
        this -> z = z;
    }
    
    Vector produceUnitVector(){
        double magnituteOfVector = calculateMagnitute();
        
        return Vector(this->x / magnituteOfVector, this->y / magnituteOfVector, this->z  / magnituteOfVector);
    }
    
    double calculateMagnitute() {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }
    
    Vector operator-(const Vector& vector) const{
        return Vector(this->x - vector.x, this->y - vector.y, this->z  - vector.z);
    }
    
    Vector operator+(const Vector& vector) const{
        return Vector(this->x + vector.x, this->y + vector.y, this->z  + vector.z);
    }
    
    
    double dotProduct(const Vector& vector) {
        return this->x * vector.x +
        this->y * vector.y +
        this->z  * vector.z;
    }
    
    Vector operator*(const Vector& point){
        return Vector(this->y * point.z - this->z*point.y,
                       -1 *(this->x * point.z - this->z*point.x),
                       this->x*point.y - this->y * point.x);
    }
    
    Vector operator*(const double& scalar) const{
        return Vector(this->x * scalar, this->y * scalar, this->z  * scalar);
        
    }
};
