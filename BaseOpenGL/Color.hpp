//
//  Color.hpp
//  BaseOpenGL
//
//  Created by Joshua Howell on 2/16/18.
//  Copyright © 2018 Joshua Howell. All rights reserved.
//

#ifndef Color_hpp
#define Color_hpp

#include <stdio.h>

#endif /* Color_hpp */

class Color {
    private:
        double red, green, blue;
    
public:
    Color(){
        red = green = blue = 0;
    }
    
    Color(double red, double green, double blue){
        this -> red = red;
        this -> green = green;
        this -> blue = blue; 
    }
    
    Color operator+(const Color& color) const{ 
        return Color(this->red + color.red, this->green + color.green, this->blue  + color.blue);
    }
    
    Color operator*(const Color& color) const{
        return Color(this->red * color.red, this->green * color.green, this->blue  * color.blue);
    }

    Color operator*(double scalar) const{
        return Color(this->red * scalar, this->green * scalar, this->blue  * scalar);
    }
};
