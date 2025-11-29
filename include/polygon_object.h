#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Point2D.h"

class Polygon_Object
{
    private:
        std::vector<Point2D> coor_poly;  //多边形的顶点
        double mass;                    //多边形的质量
        Point2D velocity;               //多边形的法向速度
        double angular_velocity;        //多边形的角速度
        double e;                       //多边形的碰撞系数
        double friction;                //多边形的摩擦系数
        double moment_of_inertia;       //多边形的转动惯量

        void get_moment_of_inertia()
        {
            /*待实现*/
        }

        void get_axis_type()
        {
            /*待实现*/
        }

        void update_physics()
        {
            get_axis_type();
            get_moment_of_inertia();
        }
    
    public:
        Polygon_Object(
            const std::vector<Point2D>& vertices,
            double _mass,
            Point2D _velocity,
            double _angular_velocity,
            double _e = 1.0,
            double _friction = 0.0
        ):
        mass(_mass),
        velocity(_velocity),
        angular_velocity(_angular_velocity)
        {
            if(vertices.size() <= 3)
            {
                throw std::invalid_argument("The coordinates must >= 3");
            }
            else
            {
                coor_poly = vertices;
            }
            if(e > 1 || e < 0)
            {
                throw std::invalid_argument("e must in 0 - 1");
            }
            else
            {
                e = _e;
            }
            if(friction > 1 || friction < 0)
            {
                throw std::invalid_argument("friction must in 0 - 1");
            }
            else
            {
                friction = _friction;
            }
        }

        //  用于读取变量的get方法
        std::vector<Point2D> get_coor_poly()const {return coor_poly;}
        double get_mass()const{return mass;}
        Point2D get_velocity() const {return velocity;}
        double get_angular_velocity() const {return angular_velocity;}
        double get_e() const {return e;}
        double get_friction() const { return friction;}

        // 用于改变变量的modify方法
        template<typename ... Args>
        void modify_coor_poly(const Point2D& p1,const Point2D& p2,const Point2D& p3,const Args& ...rest)
        {
            static_assert((std::is_same_v<Point2D,Args> && ...),
        "所有参数必须是Point2D类型")    //  类型检测

            coor_poly.clear();
            coor_poly.push_back(p1);
            coor_poly.push_back(p2);
            coor_poly.push_back(p3);
            (coor_poly.push_back(rest),...)

            update_physics();
        }

        void modify_mass(const double m) {mass = m; update_physics();}
        void modify_velocity(const Point2D& v){velocity = v;}
        void modify_angular_velocity(const double a_v){angular_velocity = a_v;}
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
};