#include <iostream>
#include <string>
#include <cmath>
#include "Vector.hpp"
using namespace std;

class Point3D {
    public:
        double x, y, z;

    Point3D (){
        
    }
        Point3D(double x, double y, double z){
            this -> x = x;
            this -> y = y;
            this -> z = z;
        }
    
    Point3D operator+(const Vector& vector) const{
        return Point3D(this->x + vector.x, this->y + vector.y, this->z  + vector.z);
    }
    
    Point3D operator-(const Vector& vector) const{
        return Point3D(this->x - vector.x, this->y - vector.y, this->z - vector.z);
    }
    
//    Point3D operator-(const Point3D& point) const{
//        return Point3D(this->x - point.x, this->y - point.y, this->z  - point.z);
//    }
    
    Vector operator-(const Point3D& point) const{
        return Vector(this->x - point.x, this->y - point.y, this->z  - point.z);
    }
    
   
    
//    Point3D operator+(const Point3D& point) const{
//        return Point3D(this->x + point.x, this->y + point.y, this->z  + point.z);
//    }
    
    Point3D operator+(const Point3D& point) const{
        return Point3D(this->x + point.x, this->y + point.y, this->z  + point.z);
    }

    
    double dotProduct(const Point3D& point) {
        return this->x * point.x +
                this->y * point.y +
                  this->z  * point.z;
    }
    
    Point3D operator*(const Point3D& point){
        return Point3D(this->y * point.z - this->z*point.y,
                        -1 *(this->x * point.z - this->z*point.x),
                            this->x*point.y - this->y * point.x);
    }
    
    Point3D operator*(const double& scalar) const{
        return Point3D(this->x * scalar, this->y * scalar, this->z  * scalar);

    }
    
  
    
    Point3D produceUnitVector(){
        double magnituteOfVector = calculateMagnitute();
        
        return Point3D(this->x / magnituteOfVector, this->y / magnituteOfVector, this->z  / magnituteOfVector);
    }
    
    double calculateMagnitute() {
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
    }
    
    
    void print(){
        cout << "Point(X: " << x;
        cout << " Y: " << y;
        cout << " Z: " << z << ")" << endl;
    }
    
    
    
   
    
    
};
