#include "polygon_object.h"
#include "circle_object.h"
#include <algorithm>

Point2D closest_point_on_segment(const Point2D& p,const Point2D& a,const Point2D& b)
{
    Point2D ab = b -a;
    double t = ( p - a).dot(ab)/ab.dot(ab);
    t = std::clamp(t,0.0,1.0);
    return a + ab * t;
}
void circle_polygon_collision_response(Circle_Object& circle,Polygon_Object& polygon)
{
    Point2D circle_center = circle.get_centroid();
    const auto& polygon_vertices = polygon.get_coor_poly();
    size_t n = polygon_vertices.size();
    double min_dist = 1e9;
    Point2D collision_normal;

    for(size_t i = 0;i < n; ++i)
    {
        Point2D a = polygon_vertices[i];
        Point2D b = polygon_vertices[(i+1)%n];
        Point2D edge = b - a;
        Point2D closest = closest_point_on_segment(circle_center,a,b);
        Point2D delta = circle_center - closest;
        double dist = delta.length();
        if(dist < min_dist)
        {
            min_dist = dist;
            collision_normal = Point2D(-edge.get_y(),edge.get_x()).normalize();

            if(collision_normal.dot(circle_center - closest) < 0)
            {
                collision_normal = collision_normal * -1;
            }
        }
    }

    Point2D tangent(-collision_normal.get_y(),collision_normal.get_x());
    double v_circle_n = circle.get_velocity().dot(collision_normal);
    double v_circle_t = circle.get_velocity().dot(tangent);
    double v_poly_n = polygon.get_velocity().dot(collision_normal);

    double e = (circle.get_e() + polygon.get_e()) / 2;
    double v_circle_n_new = (-e * (v_circle_n - v_poly_n)) + v_poly_n;

    double friction = std::min(circle.get_friction(),polygon.get_friction());
    double v_circle_t_new = v_circle_t * (1 - friction);

    Point2D v_circle_new = collision_normal * v_circle_n + tangent * v_circle_t_new;
    circle.modify_velocity(v_circle_new);

    circle.modify_angular_velocity(v_circle_t_new / circle.get_radius());
}