#include "point.h"

point::point(float x,float y)
{
    _x=x;
    _y=y;
}

float point::getX(){
    return _x;
}
float point::getY(){
    return _y;
}
