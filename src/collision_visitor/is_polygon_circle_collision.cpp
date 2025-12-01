#include "circle_object.h"
#include "polygon_object.h"
#include <algorithm>

Point2D colsest_point_on_segment(const Point2D& p,const Point2D& a,const Point2D& b)
{
    Point2D ab = b -a;
    double t = ( p - a).dot(ab)/ab.dot(ab);
    t = std::clamp(t,0.0,1.0);
    return a + ab * t;
}

bool is_centroid_in_polygon(const Point2D& p,Polygon_Object& polygon)
{
    const auto& vertices = polygon.get_coor_poly();
    size_t n = vertices.size();
    bool inside = false;
    /*待实现*/
    /*判断点是否在多边形内*/
}

bool is_circle_polygon_collision(Circle_Object& circle,Polygon_Object& polygon)
{
    const Point2D& circle_centre = circle.get_centroid();
    double circle_radius = circle.get_radius();
    const auto& polygon_vertices = polygon.get_coor_poly();
    size_t n = polygon_vertices.size();

    for(size_t i = 0;i < n;++i)
    {
        Point2D a = polygon_vertices[i];
        Point2D b = polygon_vertices[(i+1)%n];
        Point2D closest = colsest_point_on_segment(circle_centre,a,b);
        Point2D delta = circle_centre - closest;
        if(delta.length() > circle_radius + 1e-6)
        {
            return false;//无碰撞
        }
    }

    for(const auto& v : polygon_vertices)
    {
        Point2D delta = v - circle_centre;
        if(delta.length() <= circle_radius + 1e-6)
        {
            return true;
        }
    }

    if(is_centroid_in_polygon(circle_centre,polygon))
    {
        return true;
    }
    
}