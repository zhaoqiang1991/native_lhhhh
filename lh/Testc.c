//
// Created by lh on 2023-03-10.
//
#include <stdio.h>
#include <stdlib.h>
#include "c/bean/Dog.h"

void test_method1();

void test_method2();


void *test_method3(int *it, int *num);

void test_method4();

void test_method5();

mbs *sc = NULL;

int main() {
    //test_method1();
    //test_method2();
    //test_method4();
    test_method5();
    return 0;
}

void test_method1() {
    int a = 2, b = 6;
    printf("%d\n", max(&a, &b));

    bool c = false;
    printf("%d\n", c);

    int p = 100;
    printf("%d\n", sum(&p));
}

void test_method2() {
    sc = malloc(sizeof(sc));
    int i = 10;
    sc->age = &i;
    eat(sc->age);
    printf("%d\n ", *(sc->age));

}

void *test_method3(int *it, int *num) {
    if (*it > *num) {
        return it;
    }
    return num;
}

void test_method4() {
    int *p, a1 = 2, a2 = 3;
    p = test_method3(&a1, &a2);
    printf("%d\n", *p);
}

//函数指针的使用
void test_method5() {
    int a1 = 2, a2 = 4;
    getInfo = min;
    int i = getInfo(&a1, &a2);
    printf("%d\n", i);
}

