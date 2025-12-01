#include "circle_object.h"
bool is_circle_circle_collision(Circle_Object& c1,Circle_Object& c2)
{
    Point2D delta = c1.get_centroid() - c2.get_centroid();
    double dist_sq = delta.get_x()*delta.get_x() + delta.get_y()*delta.get_y();
    double sum_radius = c1.get_radius() + c2.get_radius();
    return dist_sq <= sum_radius*sum_radius + 1e-6; // 1e-6用来忽略误差
}