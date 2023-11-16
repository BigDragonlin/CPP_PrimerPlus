//
// Created by Administrator on 2023/11/15/015.
//
#include <iostream>
#include <cmath>
#include "coordin.h"

using namespace std;

polar rect_to_polar(rect xypos) {
    polar answer;
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);  //ƽ����
    answer.angle = atan2(xypos.y, xypos.x); //������
    return answer;
}

void show_polar(polar dapos){
    ::printf("------------------show_polar----\n");
    ::printf("ƽ������%d",dapos.distance);
    ::printf("�����ƣ�%d",dapos.angle);
}