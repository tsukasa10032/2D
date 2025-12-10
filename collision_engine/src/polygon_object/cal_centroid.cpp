#include <cmath>
#include "polygon_object.h"

void Polygon_Object::cal_centroid()
{
    int n = coor_poly.size();
    if(n < 3)       //  定点不足时设置为原点
    {
        centroid = Point2D();
        return;
    }

    auto points = get_coor_poly();
    double area = 0.0;
    double cx = 0.0,cy = 0.0;

    for(int i = 0; i < n; ++i)
    {
        int j = (i + 1) %n;

        double xi = points[i].get_x(),yi = points[i].get_y();
        double xj = points[j].get_x(),yj = points[j].get_y();

        double term = xi*yj - xj*yi;
        area = area + term;

        cx = cx + (xi + xj) * term;
        cy = cy + (yi + yj) * term;
    }

    area = 0.5 * fabs(area);
    if(area < 1e-9)
    {
        centroid = Point2D();
        return;
    }

    cx /= (6*area);
    cy /= (6*area);
    centroid = Point2D(cx,cy);
}