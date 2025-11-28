//  本文件用于实现坐标的各种运算   //
#include <cmath>
class Point2D
{
    private:
        double x;       //  二维下的横坐标
        double y;       //  二维下的纵坐标

    public:
        Point2D()
        {
            x = 0;
            y = 0;
        }

        //用于其他类内的初始化直接在坐标0,0生成
        
        Point2D(double _x,double _y):x(_x),y(_y){}

        //  对各个运算符进行重载实现向量的加减乘除
        Point2D operator+(const Point2D & other) const
        {
            return {x+other.x, y+other.y};
        }

        Point2D operator-(const Point2D& other) const
        {
            return {x-other.x, y-other.y};
        }

        Point2D operator*(double num) const
        {
            return {x*num, y*num};
        }

        double dot(const Point2D& other) const
        {
            return x*other.y-y*other.x;
        }

        double cross(const Point2D& other) const
        {
            return x*other.y - y*other.x;
        }

        double length() const
        {
            return std::sqrt(x*x+y*y);
        }

        Point2D normalize() const
        {
            double len = length();
            return len == 0 ? Point2D{0,0} : Point2D{x / len , y / len};
        }
};