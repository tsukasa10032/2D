#include <iostream>
#include "Point2D.h"

class Circle_Object
{
    private:
        double mass;                // 圆形的质量
        double radius;              // 圆形的半径
        Point2D velocity;           // 圆形的法向速度
        double angular_velocity;    // 圆形的角速度
        double e;                   // 恢复系数
        double friction;            // 摩擦系数
        Point2D coor_cir;           // 坐标(圆心) 。
        double moment_of_inertia;   // 转动惯量
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
        const Point2D _coor_cir = Point2D()
       ) :  
       mass(_mass),
       radius(_radius),
       velocity(_velocity),
       angular_velocity(_angular_velocity),
       e(_e),
       friction(_friction),
       coor_cir(_coor_cir),
       moment_of_inertia(0.0)
       {
        get_moment_of_inertia();
       }

       //   提供获取变量的方法get
        double get_mass() const{ return mass;}
        double get_radius() const { return radius;}
        Point2D get_velocity() const { return velocity;}
        double get_angular_velocity() const { return angular_velocity;}
        double get_e() const { return e;}
        double get_friction() const { return friction;}
        Point2D get_coor_cir() const { return coor_cir;}

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
        void modify_velocity(Point2D _velocity) {velocity = _velocity;}
        void modify_angular_velocity(double _angular_velocity) {angular_velocity = _angular_velocity;}
        void modify_e(double _e){ e = _e;}
        void modify_friction(double _friction){friction = _friction;}
};