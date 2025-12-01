#include <iostream>
#include "Point2D.h"
#include "physics_object.h"

class Circle_Object:public Physics_Object
{
    private:
        double mass;
        double radius;
        Point2D velocity;
        Point2D centroid;
        double angular_velocity;
        double e;
        double friction;
        double moment_of_inertia;
        void get_moment_of_inertia()
        {
            moment_of_inertia = 0.5*mass*radius*radius;
        }

        // 构造函数对这个圆形类进行最基础的初始化
    public:
       Circle_Object(
        double _mass,
        double _radius,
        const Point2D _velocity,
        double _angular_velocity,
        double _e = 1.0,
        double _friction = 0.0,
        const Point2D cen = Point2D()
       ) :  
       mass(_mass),
       radius(_radius),
       velocity(_velocity),
       angular_velocity(_angular_velocity),
       e(_e),
       friction(_friction),
       moment_of_inertia(0.0),
       centroid(cen)
       {
        get_moment_of_inertia();
       }
        //  get方法完全继承父类

        //  提供修改变量的方法modify
        void modify_mass(double _mass) 
        {   mass = _mass;   
            get_moment_of_inertia();
        }
        void modify_radius(double _radius) 
        {
            radius = _radius;   
            get_moment_of_inertia();
        }
        
        void update(double delta_time)
        {
            centroid = centroid + velocity*delta_time;
            if(velocity != Point2D() && friction != 0)
            {
                velocity = velocity - velocity*friction*delta_time;
            }
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
        void accept(Collision_Visitor& visitor) override;
};