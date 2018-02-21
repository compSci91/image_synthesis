//
//  Ray.hpp
//  BaseOpenGL
//
//  Created by Joshua Howell on 2/21/18.
//  Copyright © 2018 Joshua Howell. All rights reserved.
//

#ifndef Ray_hpp
#define Ray_hpp

#include <stdio.h>
#include "Point3D.hpp"

#endif /* Ray_hpp */

class Ray {
private:
    Point3D point;
    Point3D direction;
    
public:
    Ray(Point3D point, Point3D directioin){
        this -> point = point;
        this -> direction = direction; 
    }
    
  
}; 
