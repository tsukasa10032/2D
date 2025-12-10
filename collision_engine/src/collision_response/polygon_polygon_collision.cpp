#include "polygon_object.h"
#include <vector>

void polygon_polygon_collision_response(Polygon_Object& p1,Polygon_Object& p2)
{
    std::vector<Point2D> normals = get_normals(p1);
    auto normals2 = get_normals(p2);
    normals.insert(normals.end(),normals2.begin(),normals2.end());

    double min_penetration = 1e9;
    Point2D collision_normal;
    for(const auto& axis : normals)
    {
        auto [minA,maxA] = p1.projection(axis);
        auto [minB,maxB] = p2.projection(axis);
        if(!is_proj_overlap(minA,maxA,minB,maxB))
            return;

        double penetration = std::min(maxA,maxB) - std::max(minA,minB);
        if(penetration < min_penetration)
        {
            min_penetration = penetration;
            collision_normal = axis;
        }
    }

    //计算冲量
    double m1 = p1.get_mass(),m2 = p2.get_mass();
    double e = (p1.get_e() + p2.get_e()) / 2;
    double v_rel = (p2.get_velocity() - p1.get_velocity()).dot(collision_normal);
    double j = -(1+e)*v_rel/(1/m2 + 1/m2);

    //更新速度
    Point2D dv1 = collision_normal * (j / m1);
    Point2D dv2 = collision_normal * (-j / m2);
    p1.modify_velocity(p1.get_velocity() + dv1);
    p2.modify_velocity(p2.get_velocity() + dv2);
}