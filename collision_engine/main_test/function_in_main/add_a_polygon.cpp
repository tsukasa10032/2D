#include "physics_object.h"
#include <vector>
#include "polygon_object.h"
#include "Point2D.h"
#include <iostream>

void add_a_polygon(std::vector<Physics_Object*>& objs)
{
    std::vector<Point2D> vertices;
    double mass,e,friction,angular_velocity;
    Point2D velocity;
    while(true)
    {
        std::cout << "请依次输入你想创建的多边形的坐标(输入重复坐标以结束创建)" << std::endl;
        size_t n = 1;
        double x,y;
        std::cout << "请输入第" << n << "个坐标的横坐标" <<std::endl;
        std::cin >> x;
        std::cout << "请输入第" << n << "个坐标的纵坐标" << std::endl;
        std::cin >> y;
        bool is_duplicate = false;
        for(const auto& vertice : vertices)
        {
            if(vertice.get_x() == x && vertice.get_y() == y)
            {
                is_duplicate = true;
                break;
            }
        }
        if(is_duplicate)
        {
            std::cout << "检测到相同的坐标输入，创建完成" << std::endl;
            break;
        }
        else
        {
            vertices.push_back(Point2D(x,y));
            ++n;
        }
    }
    while(true)
    {
        std::cout << "请输入物体的质量" <<std::endl;
        std::cin >> mass;
        if(mass > 0)
            break;
        else
            std::cout << "物体的质量必须是正实数"<< std::endl;
    }
    while(true)
    {
        std::cout << "请输入物体碰撞系数" <<std::endl;
        std::cin >> e;
        if(e <= 1 && e >= 0)
            break;
        else
            std::cout << "物体的碰撞系数必须在0-1之间(包含)" <<std::endl;
    }
    while(true)
    {
        std::cout << "请输入物体的摩擦系数" << std::endl;
        std::cin >> friction;
        if(friction <= 1 && friction >= 0)
            break;
        else
            std::cout << "物体的摩擦系数必须在0-1之间(包含)" <<std::endl;
    }
    double v_x,v_y;
    std::cout << "请输入物体在x轴上的速度" << std::endl;
    std::cin >> v_x;
    std::cout << "请输入物体在y轴上的速度" << std::endl;
    std::cin >> v_y;
    velocity = Point2D(v_x,v_y);
    std::cout << "请输入物体的角速度" << std::endl;
    std::cin >> angular_velocity;
    objs.push_back(new Polygon_Object(vertices,mass,velocity,angular_velocity,e,friction));
}