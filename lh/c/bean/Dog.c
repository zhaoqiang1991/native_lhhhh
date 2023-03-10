//
// Created by lh on 2023-03-10.
//

#include "Dog.h"

bool max(int *it, int *num) {

    return *it > *num;
}

int sum(int *it) {
    int sum = 0;
    for (int i = 0; i < *it; i++) {
        sum += i;
    }
    return sum;
}
