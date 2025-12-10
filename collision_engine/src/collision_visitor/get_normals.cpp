#include "polygon_object.h"
#include "Point2D.h"
#include <algorithm>
std::vector<Point2D> get_normals(const Polygon_Object& polygon)
{
    std::vector<Point2D> normals;
    std::vector<Point2D> coordinates = polygon.get_coor_poly();
    size_t n = coordinates.size();
    for(size_t i = 0 ; i < n ; ++i)
    {
        Point2D edge = coordinates[(i+1)%n] - coordinates[i];
        Point2D normal(-edge.get_y(),edge.get_x());

        double normal_x;
        double normal_y;
        if(normal.length() > 1e-6)
        {
            normal_x = normal.get_x() / normal.length();
            normal_y = normal.get_y() / normal.length();
        }
        normal = Point2D(normal_x,normal_y);
        normals.push_back(normal);
    }

    return normals;
}