//
// Created by Administrator on 2023/11/15/015.
//
#include <iostream>
#include <cmath>
#include "coordin.h"

using namespace std;

polar rect_to_polar(rect xypos) {
    polar answer;
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);  //平方根
    answer.angle = atan2(xypos.y, xypos.x); //弧度制
    return answer;
}

void show_polar(polar dapos){
    ::printf("------------------show_polar----\n");
    ::printf("平方根：%d",dapos.distance);
    ::printf("弧度制：%d",dapos.angle);
}