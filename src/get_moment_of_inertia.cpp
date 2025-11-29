#include <iostream>
#include <cmath>
#include "polygon_object.h"

void Polygon_Object::get_moment_of_inertia()
{
    const size_t n = coor_poly.size();
    const double eps = 1e-6;
    if(n < 3 || mass < eps || axis_type <= 0)
    {
        moment_of_inertia = 0.0;
        return;
    }

    double area = 0.0;
    double I_c = 0.0;

    if(axis_type == AXIS_CENTROID_Y)
    {
        for(size_t i = 0;i < n;++i)
        {
            const Point2D& p1 = coor_poly[i];
            const Point2D& p2 = coor_poly[(i+1)%n];

            double x1 = p1.get_x(),y1 = p1.get_y();
            double x2 = p2.get_x(),y2 = p2.get_y();

            double cross = x1*y2 - x2*y1;
            area += cross;

            I_c += (x1*x1+x1*x2+x2*x2)*cross;
        }
    }else if(axis_type == AXIS_CENTROID_X)
    {
        for(size_t i = 0; i < n ; ++i)
        {
            const Point2D& p1 = coor_poly[i];
            const Point2D& p2 = coor_poly[(i+1)%n];

            double x1 = p1.get_x(),y1 = p1.get_y();
            double x2 = p2.get_x(),y2 = p2.get_y();

            double cross = x1*y2 - x2*y1;
            area += cross;
            I_c += (y1*y1+y1*y2+y2*y2)*cross;
        }
    }

    area = std::fabs(area)/2.0;
    if(area < eps)
    {
        moment_of_inertia = 0.0;
        return;
    }
    I_c = mass * std::fabs(I_c) / (12.0 * area);
    moment_of_inertia = I_c;
}