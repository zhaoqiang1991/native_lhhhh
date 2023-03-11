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

void eat(int *it) {
    *it = *it + 1000;
    printf("%d\n%s\n", *it, "===== 调用eat 方法");
}

int min(int *it, int *num) {
    if (*it < *num) {
        return *it;
    }
    return *num;
}
/**
 * 指针函数
 * @param it
 * @param num
 * @return
 */
int *mult(int *it, int *num) {
    int result = 0;
    result = (*it * (*num));
    return &result;
}

extern int get_info(int *it, int *num) {
    return *it + *num;
}



