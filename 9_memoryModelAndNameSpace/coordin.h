//
// Created by Administrator on 2023/11/15/015.
//

#ifndef CPP_PRIMERPLUS_COORDIN_H
#define CPP_PRIMERPLUS_COORDIN_H
struct polar
{
    double distance;
    double angle;
};

struct rect
{
    double x;
    double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
#endif //CPP_PRIMERPLUS_COORDIN_H
