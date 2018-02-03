#include "Rectangle.hpp"
#include "Point2D.cpp"
#include <stdlib.h>

class Rectangle {
    
private:
    double s[2];
    Point2D n[0];
    Point2D origin;
    
public:
    Rectangle(Point2D origin){
        this -> origin = origin;
    }
    
    void supersample(){ //not sure what this does
        const int PIXEL_WIDTH= 100; //how do I calculate this?
        const int PIXEL_HEIGHT = 100; //how do I calculate this?
        
        const int SUBPIXEL_WIDTH = 100;
        const int SUBPIXEL_HEIGHT = 100;
        
        
        
        for(int xCoordinateOfPixel = 0;  xCoordinateOfPixel < PIXEL_WIDTH; xCoordinateOfPixel++){
            for(int yCoordinateOfPixel=0; yCoordinateOfPixel < PIXEL_HEIGHT; yCoordinateOfPixel++){
                //We can now address a specific pixel;
                //Now for the supersampling
                
                for(int xCoordinateOfSubPixel=0; xCoordinateOfPixel <  SUBPIXEL_WIDTH; xCoordinateOfPixel++){
                    for(int yCoordinateOfSubPixel=0; yCoordinateOfPixel < SUBPIXEL_HEIGHT; yCoordinateOfPixel++){
                        double randomXCoordinate = ((double)rand()/(double)RAND_MAX);
                        double randomYCoordinate = ((double)rand()/(double)RAND_MAX);
                        
                        double xSamplePosition = xCoordinateOfPixel + (xCoordinateOfSubPixel + randomXCoordinate)/ SUBPIXEL_WIDTH;
                        double ySamplePosition = yCoordinateOfPixel + (yCoordinateOfSubPixel + randomYCoordinate)/ SUBPIXEL_HEIGHT;

                        
                    }
                }
            }
        }
    }
};
