#include <iostream>
#include "Point2D.h"

class Circle_Object
{
    private:
        double mass;             // 圆形的质量
        double radius;              // 圆形的半径
        Point2D velocity;            // 圆形的法向速度
        double angular_velocity;    // 圆形的角速度
        double e;                   // 恢复系数
        double friction;            // 摩擦系数
        Point2D coordinate;         // 坐标(圆心)

        //以上为一个物体的基础属性//
        double moment_of_inertia;   // 转动惯量
        void get_moment_of_inertia()
        {
            moment_of_inertia = 0.5*mass*radius*radius;
        }

    public:
        
};