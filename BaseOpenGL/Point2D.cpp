#include "Point2D.hpp"

class Point2D {
  
private:
    double x, y;
    
public:
    Point2D(){}
    
    Point2D(double x, double y){
        this->x = x;
        this->y = y; 
    }
    
    Point2D operator*(const double& scalar) const{
        return Point2D(this->x * scalar, this->y * scalar);
        
    }
    
    Point2D operator+(const Point2D& point) const{
        return Point2D(this->x + point.x, this->y + point.y);
    }
};
