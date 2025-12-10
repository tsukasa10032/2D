#include <iostream>
#include <vector>
#include "physics_object.h"
#include "circle_object.h"
#include "point2D.h"

void add_a_circle(std::vector<Physics_Object*>& objs)
{
    double x,y;
    double mass,e,friction,angular_velocity,radius;
    Point2D velocity;
    std::cout << "请输入圆形的横坐标" << std::endl;
    std::cin >> x;
    std::cout << "请输入圆形的纵坐标" << std::endl;
    std::cin >> y;
    Point2D centroid;
    centroid = Point2D(x,y);
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
        std::cout <<"请输入物体的圆形半径" <<std::endl;
        std::cin >>radius;
        if(radius > 0)
            break;
        else
            std::cout << "物体的圆形半径必须是正实数" << std::endl;
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
    objs.push_back(new Circle_Object(mass,radius,velocity,angular_velocity,e,friction,centroid));
}