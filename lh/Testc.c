//
// Created by lh on 2023-03-10.
//
#include <stdio.h>
#include "c/bean/Dog.h"

int main() {
    printf("========  c方法");

    int a = 2,b = 6;
    printf("%d\n",max(&a, &b));

    bool  c = false;
    printf("%d\n",c);

    int p = 100;
    printf("%d\n",sum(&p));
    return 0;
}

