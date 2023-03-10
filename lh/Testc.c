//
// Created by lh on 2023-03-10.
//
#include <stdio.h>
#include <stdlib.h>
#include "c/bean/Dog.h"

void test_method1();

void test_method2();

mbs *sc = NULL;

int main() {
    //test_method1();
    test_method2();
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
    printf("%d\n ",*(sc->age));

}

