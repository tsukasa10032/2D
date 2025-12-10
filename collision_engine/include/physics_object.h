#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H

#include <iostream>
#include <cmath>
#include "Point2D.h"
#include "collision_visitor.h"

class Physics_Object
{
    protected:
        Point2D centroid;           //位置(质心),(假设均匀的情况,圆形质心即为圆心)
        Point2D velocity;           //法相速度
        double mass;                //质量
        double angular_velocity;    //角速度
        double moment_of_inertia;   //转动惯量
        double friction;            //摩擦系数
        double e;                   //碰撞系数
        double radius;              //旋转半径(多边形中计算，圆形即半径)
    public:
            virtual ~Physics_Object() = default;
            //都支持的get方法
            virtual Point2D get_centroid(){return centroid;}
            virtual double get_mass(){return mass;}
            virtual Point2D get_velocity(){return velocity;}
            virtual double get_angular_velocity(){return angular_velocity;}
            virtual double get_e(){return e;};
            virtual double get_friction(){return friction;}
            virtual double get_radius() {return radius;}
            //都支持的modify方法
            void modify_velocity(const Point2D& v){velocity = v;}
            void modify_angular_velocity(const double a_v){angular_velocity = a_v;}
            void modify_centroid(const Point2D& cen){centroid = cen;}
            void modify_e(const double _e)
            {
                if(_e > 1 || _e < 0)
                {
                    throw std::invalid_argument("碰撞系数必须在0-1之间");
                }
                else
                    e = _e;
            }
            void modify_friction(const double f)
            {
                if(f > 1 || f < 0)
                {
                   throw std::invalid_argument("摩擦系数必须在0-1之间");
                }
                else
                    friction = f;
            }

            virtual void update(double delta_time) = 0;
            virtual void accept(Collision_Visitor& visitor) = 0;

};

#endif