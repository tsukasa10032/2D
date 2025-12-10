#ifndef PYSICAL_MANAGER_H
#define PYSICAL_MANAGER_H

template <typename T,typename U>
class Pysical_Manager
{
    private:
        T object1;
        U object2;

    public:
        Pysical_Manager(T one,U two):object1(one),object2(two){}

        void check_and_resolve_collision()
        {
            if constexpr (std::is_same_v<T,Circle_Object> && std::is_same_v<U,Circle_Object>)
            {
                if(is_circle_circle_collision(object1,object2))
                {
                    circle_circle_collision_response(object1,object2);
                }
            }
            else if constexpr(std::is_same_v<T,Polygon_Object> && std::is_same_v<U,Circle_Object>)
            {
                if(is_circle_polygon_collision(obejct2,object1))
                {
                    circle_polygon_collision_response(object2,object1);      
                }
            }

            else if constexpr(std::is_same_v<T,Polygon_Object> && std::is_same_v<U,Polygon_Object>)
            {
                if(is_polygon_polygon_collision(object1,object2))
                {
                    polygon_polygon_collision_response(object1,object2);
                }
            }
        }
};

#endif