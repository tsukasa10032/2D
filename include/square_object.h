#include <iostream>
#include <vector>
#include <cmath>
#include <array>
#include "Point2D.h"

class Square_Object
{
    private:
        std::array<Point2D,4> coor_sq;  //  矩形的坐标
        double mass;                    //  矩形的质量
        Point2D velocity;               //  矩形的法相速度
        double angular_velocity;        //  矩形的角速度
        double e;                       //  碰撞系数
        double friction;                //  摩擦系数
        double moment_of_inertia;       //  转动惯量

    public:
        Square_Object(
            const Point2D A,
            const Point2D B,
            const Point2D C,
            const Point2D D,
            double _mass,
            const Point2D _velocity,
            double _angular_velocity,
            double _e,
            double _friction
        ):
        coor_sq({A,B,C,D}),
        mass(_mass),
        velocity(_velocity),
        angular_velocity(_angular_velocity),
        e(_e),
        friction(_friction){}

        //  提供获取变量的get方法
        std::vector<Point2D> get_coor_sq(){return {coor_sq[0],coor_sq[1],coor_sq[2],coor_sq[3]};}
        double get_mass(){return mass;}
        Point2D get_velocity(){return velocity;}
        double get_angular_velocity(){return angular_velocity;}
        double get_e(){return e;}
        double get_friction(){return friction;}

        //  提供修改变量的modify方法
        void modify_coor_sq(const Point2D A,const Point2D B,const Point2D C,const Point2D D)
        {coor_sq = {A,B,C,D};}
        void modify_mass(double _mass){mass = _mass;}
        void modify_velocity(Point2D _velocity){velocity = _velocity;}
        void modify_angular_velocity(double _angular_velocity){angular_velocity = _angular_velocity;}
        void modify_e(double _e){e = _e;}
        void modify_friction(double _friction){friction = _friction;}
};