#include <vector>
#include <iostream>
#include <array>
#include "Point2D.h"
#include <cmath>

class Triangle_Object
{
    private:
        std::array<Point2D,3> coor_tri; // 用于存储三角形的三个顶点
        double mass;                    // 三角形的质量
        Point2D velocity;                // 三角形的法向速度
        double angular_velocity;        // 三角形的角速度
        double e;                       // 恢复系数
        double friction;                // 摩擦系数
        double moment_of_inertia;       // 转动惯量
        int axis_type;                  // 转轴类型

        double distance_to_segment(const Point2D& P,const Point2D& A,const Point2D& B) const
        {
            Point2D AB = B - A;
            Point2D AP = P - A;
            double shadow = AP.dot(AB); // 投影长度
            /*待实现*/
        }

        void compute_axis_type()
        {

        }

        void calculate_moment_inertia()
        {
            switch(axis_type)
            {
                case 1:
                    moment_of_inertia = (1.0/12.0)*mass;
                    /*待实现*/
            }
        }

    public:
        Triangle_Object(
            const Point2D A,
            const Point2D B,
            const Point2D C,
            double _mass,
            const Point2D _velocity,
            double _angular_velocity,
            double _e,
            double _friction
        ):
        coor_tri({A,B,C}),
        mass(_mass),
        velocity(_velocity),
        angular_velocity(_angular_velocity),
        e(_e),
        friction(_friction)
        {}

        //  提供获取对应变量的方法get
        std::vector<Point2D> get_coor_tri()
        {return {coor_tri[0],coor_tri[1],coor_tri[2]};}
        double get_mass()
        {return mass;}
        Point2D get_velocity()
        { return velocity;}
        double get_angular_velocity()
        {return angular_velocity;}
        double get_e(){return e;}
        double get_friction(){return friction;}

        //  提供修改变量的方法modify
        void modify_point(const Point2D A,const Point2D B,const Point2D C)
        { coor_tri = {A,B,C};}
        void modify_mass(double _mass) {mass = _mass;}
        void modify_velocity(Point2D _velocity){ velocity = _velocity;}
        void modify_angular_velocity(double _angular_velocity){angular_velocity = _angular_velocity;}
        void modify_e(double _e){e = _e;}
        void modify_friction(double _friction){friction = _friction;}
};