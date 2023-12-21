#include <cassert>
#include <iostream>

//
// Created by Administrator on 2023/12/21/021.
//
void myFunction(int value)
{
    assert(value < 0);//断言,如果value小于0,则程序终止
    std::cout << "value = " << value << std::endl;
}

int main() {
    myFunction(-1);
    myFunction(1);
}