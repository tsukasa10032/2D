#include "circle_object.h"
#include "polygon_object.h"
#include <algorithm>


bool is_centroid_in_polygon(const Point2D& p,Polygon_Object& polygon)
{
    const auto& vertices = polygon.get_coor_poly();
    size_t n = vertices.size();
    bool inside = false;
    for(size_t i = 0,j = n - 1 ; i < n;j = i++) //索引多边形所有的边初始化j为n-1表示多边形的最后一个顶点
    {
        if((vertices[i].get_y() > p.get_y()) != (vertices[j].get_y() > p.get_y())&&
        (p.get_x() < (vertices[j].get_x() - vertices[i].get_x())*(p.get_y()-vertices[i].get_y()) / 
        (vertices[j].get_y() - vertices[i].get_y()) + vertices[i].get_x()))
        {inside = !inside;}
    }   //  射线法判断:
        //  第一部分:(vertices[i].get_y() > p.get_y()) != (vertices.[j].get_y() > p.get_y())
        //  这个部分用于判断p的水平线(y = p.get_y())是否穿过当前的边

        //  第二部分实在看不懂了搜索一下射线法
        //  原理: 从点p向右发射一条水平射线,统计射线与多边形边的相交次数:
        //  次数为奇数: 点在多边形内部
        //  次数为偶数: 点在多边形外部

    return inside;
}

bool is_circle_polygon_collision(Circle_Object& circle,Polygon_Object& polygon)
{
    const Point2D& circle_centre = circle.get_centroid();
    double circle_radius = circle.get_radius();
    const auto& polygon_vertices = polygon.get_coor_poly();
    size_t n = polygon_vertices.size();

    for(size_t i = 0;i < n;++i)
    {
        Point2D a = polygon_vertices[i];
        Point2D b = polygon_vertices[(i+1)%n];
        Point2D closest = closest_point_on_segment(circle_centre,a,b);
        Point2D delta = circle_centre - closest;
        if(delta.length() > circle_radius + 1e-6)
        {
            return false;//无碰撞
        }
    }

    for(const auto& v : polygon_vertices)
    {
        Point2D delta = v - circle_centre;
        if(delta.length() <= circle_radius + 1e-6)
        {
            return true;
        }
    }

    if(is_centroid_in_polygon(circle_centre,polygon))
    {
        return true;
    }
    
    return false;
}