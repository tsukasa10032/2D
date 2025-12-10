#include <iostream>
#include <cmath>
#include "polygon_object.h"

void Polygon_Object::cal_axis_type()
{
    const size_t n = coor_poly.size();
    if(n < 3 || std::isnan(centroid.get_x()) || std::isnan(centroid.get_y()))
    {
        axis_type = AXIS_INVAILD;
         return;
    }
    
    axis_type = AXIS_CENTROID_Y;
}