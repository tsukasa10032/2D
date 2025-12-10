#include "polygon_object.h"
#include <vector>

std::pair<double,double> projection(const Polygon_Object& polygon,const Point2D& axis)  // 投影函数返回投影的最大最小值
{
    std::vector<Point2D> vertices = polygon.get_coor_poly();
    double min_proj = vertices[0].get_x() * axis.get_x() + vertices[0].get_y() * axis.get_y();
    double max_proj = min_proj;
    for(const Point2D& v : vertices)
    {
        double proj = v.get_x() * axis.get_x() + v.get_y() * axis.get_y();
        min_proj = std::min(min_proj,proj);
        max_proj = std::max(max_proj,proj);
    }

    return {min_proj,max_proj};
}