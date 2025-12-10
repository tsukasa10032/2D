#include "Point2D.h"
#include <algorithm>

Point2D closest_point_on_segment(const Point2D& p,const Point2D& a,const Point2D& b)
{
    Point2D ab = b -a;
    double t = ( p - a).dot(ab)/ab.dot(ab);
    t = std::clamp(t,0.0,1.0);
    return a + ab * t;
}