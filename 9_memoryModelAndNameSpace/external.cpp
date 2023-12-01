//
// Created by Administrator on 2023/11/21/021.
//
#include <iostream>
using namespace std;

double warming = 0.3;

void update(double dt);
void local();
int externalMain(){
    ::printf("global warming is %f",warming);
    update(0.1);
    ::printf("global warming is %f",warming);
    local();
    ::printf("global warming is %f",warming);
    return 0;
}