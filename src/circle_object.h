#include <iostream>

class Circle_Object
{
    private:
        double quality;             // 圆形的质量
        double radius;              // 圆形的半径
        double velocity;            // 圆形的法向速度
        double angular_velocity;    // 圆形的角速度
        double e;                   // 恢复系数
        double friction;            // 摩擦系数
        Point2D coordinate;         // 坐标(圆心)

        //以上为一个物体的基础属性//
        double moment_of_inertia;   // 转动惯量
        void get_moment_of_inertia()
        {
            moment_of_inertia = 0.5*quality*velocity*velocity;
        }

    public:
        Circle_Object(double Q,double R,double V,double W,double E,double F)
        :quality(Q),radius(R),velocity(V),angular_velocity(W),e(E),friction(F){}
        //  构造函数提供了所有可有定义的值
        Circle_Object(double Q,double R,double V)
        :quality(Q),radius(R),velocity(V),angular_velocity(0.0),e(1.0),friction(0.0){}
        //  默认情况下最少需要三个值(速度,质量,半径)剩下的初始化为最理想状态

         Circle_Object(double Q,double R,double V,double A)
        :quality(Q),radius(R),velocity(V),angular_velocity(A),e(1.0),friction(0.0){}
         Circle_Object(double Q,double R,double V,double E)
        :quality(Q),radius(R),velocity(V),angular_velocity(0.0),e(E),friction(0.0){}
         Circle_Object(double Q,double R,double V,double F)
        :quality(Q),radius(R),velocity(V),angular_velocity(0.0),e(1.0),friction(F){}
         Circle_Object(double Q,double R,double V,double A,double E)
        :quality(Q),radius(R),velocity(V),angular_velocity(A),e(E),friction(0.0){}
         Circle_Object(double Q,double R,double V,double A,double F)
        :quality(Q),radius(R),velocity(V),angular_velocity(A),e(1.0),friction(F){}
         Circle_Object(double Q,double R,double V,double E,double F)
        :quality(Q),radius(R),velocity(V),angular_velocity(0.0),e(E),friction(F){}
        //  各种情况的构造函数，要求后三个变量必须按照顺序输入(中间可跳过)

        Circle_Object(const Circle_Object& other)
        {
            this->quality = other.quality;
            this->radius = other.radius;
            this->velocity = other.velocity;
            this->angular_velocity = other.angular_velocity;
            this->e = other.e;
            this->friction = other.friction;

            //  深拷贝用于复制一个完全相同的圆形二维物体
        }
};