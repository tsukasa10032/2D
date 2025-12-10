#include "circle_object.h"

void circle_circle_collision_response(Circle_Object& c1,Circle_Object& c2)
{
    Point2D delta = c2.get_centroid() - c1.get_centroid();
    double dist = delta.length();
    if(dist < 1e-6 )
        dist = 1e-6;

    Point2D normal = delta.normalize();                 //用来处理速度分量的法线
    Point2D tangent(-normal.get_y(),normal.get_x());    //用来处理速度分量的切线

    double v1n = c1.get_velocity().dot(normal);
    double v1t = c1.get_velocity().dot(tangent);

    double v2n = c2.get_velocity().dot(normal);
    double v2t = c2.get_velocity().dot(tangent);

    //计算法线方向的新速度
    double m1 = c1.get_mass(),m2 = c2.get_mass();
    double e = (c1.get_e() + c2.get_e());               //计算平均碰撞系数
    //计算的具体实现
    double v1n_new = ((m1 - e*m2)*v1n + (m2*(1+e))*v2n)/(m1 + m2);
    double v2n_new = ((m2 - e*m1)*v2n + (m1*(1+e))*v1n)/(m1 + m2);

    //计算碰撞后的切线方向的速度
    double f1 = c1.get_friction(),f2 = c2.get_friction();
    double friction = std::min(f1,f2);                      //摩擦系数大小由最小的计算
    double v1t_new = v1t * (1 - friction);
    double v2t_new = v2t * (1 - friction);

    //合成新速度
    Point2D v1_new = normal*v1n_new + tangent*v1t_new;
    Point2D v2_new = normal*v2n_new + tangent*v2t_new;
    c1.modify_velocity(v1_new);
    c2.modify_velocity(v2_new);

    //更新角速度
    double c1_a_new = v1t_new / c1.get_radius();
    double c2_a_new = v2t_new / c2.get_radius();
    c1.modify_angular_velocity(c1_a_new);
    c2.modify_angular_velocity(c2_a_new);

    
}