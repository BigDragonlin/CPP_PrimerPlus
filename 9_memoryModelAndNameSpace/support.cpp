//
// Created by Administrator on 2023/11/21/021.
//
#include <iostream>
using namespace std;
extern double warming;

void update(double dt);

void local();

void update(double dt) {
    extern double warming;
    warming += dt;
    ::printf("warming is %f",warming);
}

void local() {
    double warming = 0.8;
    ::printf("local warming is %f",warming);
    ::printf("global warimg is %f",::warming);
}
