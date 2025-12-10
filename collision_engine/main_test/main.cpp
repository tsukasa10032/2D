#include "Point2D.h"
#include "physics_object.h"
#include "circle_object.h"
#include "polygon_object.h"
#include "collision_world.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>


void graphic_create(std::vector<Physics_Object*> objs);

int main(void)
{
    std::cout << "本测试程序只可以用来演示基本功能,技术力不足无法实现图形化界面" << std::endl;
    for(size_t n = 0 ; n < 15 ; ++n)
        std::cout << '*';
    std::cout << std::endl;

    std::vector<Physics_Object*> objs;
    graphic_create(objs);

    double left = 0,right = 100,top = 100,bottom = 0;
    int select;
    std::cout << "\n选择是否创建一个碰撞边界" << std::endl;
    std::cout << "1.创建                                        0.不创建" <<std::endl;
    std::cin >> select;
    if(select != 0)
    {
        std::cout << "请输入边界范围(左 右 上 下)" <<std::endl;
        std::cin >> left >> right >> top >> bottom;
    }
    Collision_World world(left,right,top,bottom);

    //将创建的物体添加到碰撞世界中
    for(auto obj : objs)
    {
        world.add_object(obj);
    }

    //更新物理更新循环
    const double frame_rate = 60.0;
    const double delta_time = 1.0 / frame_rate;
    std::cout << "\n开始模拟(Ctrl + C来退出)" << std::endl;


    while(true)
    {
        auto start = std::chrono::high_resolution_clock::now();

        world.update(delta_time);

        static int frame_count = 0;
        if(frame_count % 10 == 0)
        {
            std::cout << "\n=== 第" << frame_count << "帧状态 ===" << std::endl;
            for(size_t i = 0;i <objs.size();++i)
            {
                auto& obj = objs[i];
                std::cout << "物体" << i+1 << "："
                          << "质心(" << obj->get_centroid().get_x() << "," << obj->get_centroid().get_y() << "), "
                          << "速度(" << obj->get_velocity().get_x() << "," << obj->get_velocity().get_y() << ")" << std::endl;
            }
        }
        frame_count++;

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        if (elapsed.count() < delta_time) {
            std::this_thread::sleep_for(std::chrono::duration<double>(delta_time - elapsed.count()));
        }

        for(auto obj : objs)
        {
            delete obj;
        }
        return 0;
    }
}