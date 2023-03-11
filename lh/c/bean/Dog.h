//
// Created by lh on 2023-03-10.
//

#include <stdbool.h>
#include <stdio.h>

#ifndef LH_DOG_H
#define LH_DOG_H
typedef struct strDog {
    int *age;
} mbs;

extern mbs *sc;

extern void eat(int *it);

#endif //LH_DOG_H

bool max(int *it, int *num);

int min(int *it, int *num);

int sum(int *it);

/**
 * 函数指针，函数指针执行的函数的返回值不能只指针，只能是
 * 其他类型，比如基本类型或者对象
 * @param it
 * @param num
 * @return
 */
int (*getInfo)(int *it, int *num);

int * mult(int *it, int *num);

/*
typedef int (*fun)(int, int);
*/

