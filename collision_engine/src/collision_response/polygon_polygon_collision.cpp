#include "polygon_object.h"
#include <vector>
std::vector<Point2D> get_normals(const Polygon_Object& polygon)
{
    std::vector<Point2D> normals;
    std::vector<Point2D> coordinates = polygon.get_coor_poly();
    size_t n = coordinates.size();
    for(size_t i = 0 ; i < n ; ++i)
    {
        Point2D edge = coordinates[(i+1)%n] - coordinates[i];
        Point2D normal(-edge.get_y(),edge.get_x());

        double normal_x;
        double normal_y;
        if(normal.length() > 1e-6)
        {
            normal_x = normal.get_x() / normal.length();
            normal_y = normal.get_y() / normal.length();
        }
        normal = Point2D(normal_x,normal_y);
        normals.push_back(normal);
    }

    return normals;
}
bool is_proj_overlap(double minA,double maxA,double minB,double maxB)
{
    return !(maxA<minB || maxB < minA);
}

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