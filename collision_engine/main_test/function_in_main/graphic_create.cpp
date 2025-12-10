#include <iostream>
#include <vector>
#include "physics_object.h"
#include <cstdlib>
void add_a_circle(std::vector<Physics_Object*>& objs);
void add_a_polygon(std::vector<Physics_Object*>& objs);
void graphic_create(std::vector<Physics_Object*>& objs)
{
    while(1)
    {
        size_t n;
        std::cout << "请输入你想要创建的图形(输入0-2的数字)"<<std::endl;
        std::cout << "1.圆形                  2.多边形                      0.结束创建(如果没有图形自动结束程序)";
        std::cin >> n;
        if(n == 1)
        {
            add_a_circle(objs);
        }
        else if(n == 2)
        {
            add_a_polygon(objs);
        }
        else if(n == 0)
        {
            break;
        }
        else
        {
            std::cerr << "请输入0-2之间的数字" << std::endl;
        }
        if(objs.empty())
        {
            std::cout << "没有创建任何物体,程序退出"  << std::endl;
            std::exit(EXIT_SUCCESS);
        }
    }
}