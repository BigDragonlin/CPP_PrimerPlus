//
// Created by Dream on 2023/11/16.
//
#include <iostream>
using namespace std;

#include "StorageDuringScopeAndLinkage.h"
#include "9_memeryModelAndNameSpace.h"

void oil(int texas);

void StorageDuringScopeAndLinkageShow() {
    //≥Ã–Ú«Âµ•9.4
    Auto();
}

void Auto() {
    static int staticVar;
    int texas;
    printf("staticVar is %d, &staticVar is %p\n", staticVar, &staticVar);
    printf("test is %d, &test is %p\n", texas, &texas);
    printf("--------------------\n");
    texas = 31;
    staticVar = 30;
    int year = 2023;
    printf("staticVar is %d, &staticVar is %p\n", staticVar, &staticVar);
    printf("texas is %d, &texas is %p\n", texas, &texas);
    printf("year is %d, &year is %p\n", year, &year);
    oil(texas);
    printf("texas is %d, &texas is %p\n", texas, &texas);
    printf("year is %d, &year is %p\n", year, &year);
}

void oil(int x) {
    int texas = 5;
    printf("In oil(), texas = %d, &texas = %p\n", texas, &texas);
    printf("In oil(), x = %d, &x = %p\n", x, &x);
    {
        int texas = 113;
        printf("In block, texas = %d, &texas = %p\n", texas, &texas);
        printf("In block, x = %d, &x = %p\n", x, &x);
    }
    printf("Post-block texas = %d, &texas = %p\n", texas, &texas);
}
