#include "polygon_object.h"
#include "circle_object.h"

class Collision_Visitor
{
    public:
        virtual ~Collision_Visitor() = default;

        virtual void visit(Circle_Object& circle1,Circle_Object& circle2) = 0;
        virtual void visit(Circle_Object& circle,Polygon_Object& polygon) = 0;
        virtual void visit(Polygon_Object& polygon,Circle_Object& circle) = 0;
        virtual void visit(Polygon_Object& polygon1,Polygon_Object& Polygon2) = 0;  

};