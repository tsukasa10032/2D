//用于判断两个投影区间是否重叠
bool is_proj_overlap(double minA,double maxA,double minB,double maxB)
{
    return !(maxA<minB || maxB < minA);
}