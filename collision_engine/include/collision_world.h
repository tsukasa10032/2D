#ifndef COLLISION_WORLD_H
#define COLLISION_WORLD_H

/*创建一个用于建立碰撞世界的区域*/
#include "physics_object.h"
#include "circle_object.h"
#include "polygon_object.h"
#include "collision_visitor.h"
#include <vector>
#include "Point2D.h"
#include <algorithm>

class Collision_World;

bool is_circle_circle_collision(Circle_Object& c1,Circle_Object& c2);
void circle_circle_collision_response(Circle_Object& c1,Circle_Object& c2);
bool is_circle_polygon_collision(Circle_Object& c,Polygon_Object& p);
void circle_polygon_collision_response(Circle_Object& c,Polygon_Object& p);
bool is_polygon_polygon_collision(Polygon_Object& p1,Polygon_Object& p2);
void polygon_polygon_collision_response(Polygon_Object& p1,Polygon_Object& p2);
void collision_edge_detect(const Collision_World& world,Physics_Object& object);

class Collision_World
{
    private:
        std::vector<Physics_Object*> objects;    //管理物体
        double left,right,top,bottom;           //边界范围
    
    public:
        Collision_World(double l,double r,double t,double b):
        left(l),right(r),top(t),bottom(b){}

        void add_object(Physics_Object* obj)
        {
            objects.push_back(obj);
        }

        void remove_object(Physics_Object* obj)
        {
            auto it = std::find(objects.begin(),objects.end(),obj);
            if(it != objects.end())
                objects.erase(it);
        }

        double get_left() const {return left;}
        double get_right() const {return right;}
        double get_top() const {return top;}
        double get_bottom() const {return bottom;}

        void update(double delta_time)
        {
            for(auto obj: objects)
            {
                obj->update(delta_time);
                collision_edge_detect(*this,*obj);
            }

            for(size_t i = 0; i < objects.size();++i)
            {
                for(size_t j = i + 1;j < objects.size() ; ++j)
                {   auto* o1 = objects[i];
                    auto* o2 = objects[j];

                    //圆形碰撞
                    if(auto* c1 = dynamic_cast<Circle_Object*>(o1);c1)
                    {
                        if(auto* c2 = dynamic_cast<Circle_Object*>(o2);c2)
                        {
                            if(is_circle_circle_collision(*c1,*c2))
                            {
                                circle_circle_collision_response(*c1,*c2);
                            }
                        }
                    }

                    //圆形多边形碰撞
                    if(auto* c = dynamic_cast<Circle_Object*>(o1);c)
                    {
                        if(auto * p = dynamic_cast<Polygon_Object*>(o2);p)
                        {
                            if(is_circle_polygon_collision(*c,*p))
                            {
                                circle_polygon_collision_response(*c,*p);
                            }
                        }
                    }
                    if(auto *p = dynamic_cast<Polygon_Object*>(o1);p)
                    {
                        if(auto * c = dynamic_cast<Circle_Object*>(o2);c)
                        {
                            if(is_circle_polygon_collision(*c,*p))
                            {
                                circle_polygon_collision_response(*c,*p);
                            }
                        }
                    }

                    //多边形多边形碰撞
                    if(auto *p1 = dynamic_cast<Polygon_Object*>(o1);p1)
                    {
                        if(auto * p2 = dynamic_cast<Polygon_Object*>(o2);p2)
                        {
                            if(is_polygon_polygon_collision(*p1,*p2))
                            {
                                polygon_polygon_collision_response(*p1,*p2);
                            }
                        }
                    }
                }
            }
        }
};

#endif