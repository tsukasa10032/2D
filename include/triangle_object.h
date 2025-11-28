#include <iostream>
#include <array>
#include "Point2D.h"
#include <cmath>

class Triangle_Object
{
    private:
        std::array<Point2D,3> coor_tri; // 用于存储三角形的三个顶点
        double mass;                 // 三角形的质量
        double velocity;                // 三角形的法向速度
        double e;                       // 恢复系数
        double friction;                // 摩擦系数

        double distance_to_segment(const Point2D& P,const Point2D& A,const Point2D& B) const
        {
            Point2D AB = B - A;
            Point2D AP = P - A;
            double shadow = AP.dot(AB); // 投影长度
            /*待实现*/
        }

    public:
        Triangle_Object()
    
};