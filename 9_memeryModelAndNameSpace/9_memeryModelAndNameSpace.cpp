//
// Created by Administrator on 2023/11/15/015.
//
#include <iostream>
#include "coordin.h"
using namespace std;
/*9.1 ��������
 *- ��Ҫ�Ѷ���ŵ�ͷ�ļ��У���������������
 *- <include> ���������ұ�׼�����ͷ�ļ�
 *- ��include"�����������ڱ��ز��ң�Ȼ����ȥ�ұ�׼������ļ������������Լ����ļ�������˫����
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