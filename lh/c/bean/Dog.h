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

int sum(int *it);

/*
typedef int (*fun)(int, int);
*/

