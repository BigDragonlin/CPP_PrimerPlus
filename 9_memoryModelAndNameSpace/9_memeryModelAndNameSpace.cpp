//
// Created by Administrator on 2023/11/15/015.
//
#include <iostream>
#include "coordin.h"
using namespace std;
/*9.1 单独编译
 *- 不要把定义放到头文件中，这样可能有问题
 *- <include> 编译器会找标准库里的头文件
 *- “include"编译器会现在本地查找，然后再去找标准库里的文件。我们引入自己的文件，都用双引号
 *
 * */

void memoryModelAndNameSpaceMain(){
    polar m_polar;
    rect m_rect;

    printf("please enter x and y");
    while (cin>>m_rect.x>>m_rect.y){
        m_polar = rect_to_polar(m_rect);
        show_polar(m_polar);
    }
}