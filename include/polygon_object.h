#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Point2D.h"
#include "physics_object.h"

#define AXIS_INVAILD 0      //无效轴
#define AXIS_CENTROID_X 1   //质心X轴
#define AXIS_CENTROID_Y 2   //质心Y轴

class Polygon_Object:public Physics_Object
{
    private:
        double mass;
        double angular_velocity;
        Point2D velocity;
        Point2D centroid;
        double friction;
        double e;
        double moment_of_inertia;
        double radius;
        std::vector<Point2D> coor_poly;  //多边形的顶点
        int axis_type;                  //转轴类型

        void cal_radius()
        {
            radius = sqrt(moment_of_inertia/mass);
        }
        void cal_moment_of_inertia();
        void cal_axis_type();
        void cal_centroid();
        void update_physics()
        {
            cal_centroid();
            cal_axis_type();
            cal_moment_of_inertia();
            cal_radius();
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
        angular_velocity(_angular_velocity),
        e(_e),
        friction(_friction),
        radius(0.0),
        moment_of_inertia(0.0),
        axis_type(AXIS_INVAILD)
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
            update_physics();
        }

        //  用于读取变量的get方法
        std::vector<Point2D> get_coor_poly()const {return coor_poly;}
        std::pair<double,double> projection(const Point2D& axis) const;    //计算多边形在某轴上的投影区间(min,max)

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
        void modify_centroid_axis(int type)
        {
            if(type != AXIS_CENTROID_X && type != AXIS_CENTROID_Y)
            {
                throw std::invalid_argument("仅支持质心X/Y轴");
            }
            axis_type = type;
            cal_moment_of_inertia();
        }

        void update(double delta_time) override;
        void accept(Collision_Visitor& visitor) override;
};