/*用于检测边界碰撞*/
#include "physics_object.h"
#include "collision_world.h"

void collision_edge_detect(const Collision_World& world,Physics_Object& object)
{
    Point2D pos = object.get_centroid();
    double radius = object.get_radius();
    Point2D vel = object.get_velocity();
    double e = object.get_e();

    //左边界
    if(pos.get_x() - radius < world.get_left())
    {
        object.modify_velocity(Point2D(-vel.get_x()*e,vel.get_y()));
        object.modify_centroid(Point2D(world.get_left() + radius,pos.get_y())); 
    }
    
    //右边界
    if(pos.get_x() + radius > world.get_right())
    {
        object.modify_velocity(Point2D(-vel.get_x()*e,vel.get_y()));
        object.modify_centroid(Point2D(world.get_right() - radius,pos.get_y()));
    }

    //上边界
    if(pos.get_y() + radius > world.get_top())
    {
        object.modify_velocity(Point2D(vel.get_x(),-vel.get_y()*e));
        object.modify_centroid(Point2D(pos.get_x(),world.get_top() - radius));
    }

    //下边界
    if(pos.get_y() - radius < world.get_bottom())
    {
        object.modify_velocity(Point2D(vel.get_x(),-vel.get_y()*e));
        object.modify_centroid(Point2D(pos.get_x(),world.get_bottom() + radius));
    }
}