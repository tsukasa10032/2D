#include "polygon_object.h"
void Polygon_Object::update(double delta_time)
{
    centroid = centroid + velocity * delta_time;
    for(auto& coordinate : coor_poly)
    {
        coordinate = coordinate + velocity * delta_time;
    }
    if(velocity != Point2D() && friction != 0)
        velocity = velocity - velocity*friction*delta_time;
    if(std::abs(velocity.get_x()) < 1e-6) velocity.modify_x(0.0);
    if(std::abs(velocity.get_y()) < 1e-6) velocity.modify_y(0.0);
    if(angular_velocity != 0)
    {
        const double gravity = 9.8;
        const double decay_coeff = (4*friction*gravity)/(3*radius);     //物理公式计算角减速度
        double new_angular_velocity = angular_velocity - decay_coeff*delta_time;
        angular_velocity = std::max(new_angular_velocity,0.0);
    }
}