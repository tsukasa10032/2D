#include "polygon_object.h"
#include <vector>

bool is_proj_overlap(double minA,double maxA,double minB,double maxB);
std::pair<double,double> projection(const Polygon_Object& polygon,const Point2D& axis);

bool is_polygon_polygon_collision(Polygon_Object& o1,Polygon_Object& o2)
{
    std::vector<Point2D> normals = get_normals(o1);
    std::vector<Point2D> normalsB = get_normals(o2);
    normals.insert(normals.end(),normalsB.begin(),normalsB.end());

    for(const Point2D& axis : normals)
    {
        auto [minA,maxA] = projection(o1,axis);
        auto [minB,maxB] = projection(o2,axis);

        if(!is_proj_overlap(minA,maxA,minB,maxB))
        {
            return false;
        }
    }

    return true;
}



//用于判断两个投影区间是否重叠
bool is_proj_overlap(double minA,double maxA,double minB,double maxB)
{
    return !(maxA<minB || maxB < minA);
}

std::vector<Point2D> get_normals(const Polygon_Object& polygon);