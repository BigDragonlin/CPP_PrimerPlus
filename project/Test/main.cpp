#include <cassert>
#include <iostream>

//
// Created by Administrator on 2023/12/21/021.
//
void myFunction(int value)
{
    assert(value < 0);//����,���valueС��0,�������ֹ
    std::cout << "value = " << value << std::endl;
}

int main() {
    myFunction(-1);
    myFunction(1);
}