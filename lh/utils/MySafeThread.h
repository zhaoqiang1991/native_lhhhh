//
// Created by lh on 2023-05-24.
//

#ifndef LH_MYSAFETHREAD_H
#define LH_MYSAFETHREAD_H

#include <sys/_pthread/_pthread_mutex_t.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

//队列是队尾进，队首出
typedef struct {
    //数组存储元素
    int *buffer;
    int item;
    int capacity;
    int front;
    int size;
    int rear;
    //锁
    pthread_mutex_t lock;

} my_safe_thread;

/**
 * 初始化队列
 * @param queue
 * @param capacity
 * @param item
 */
void initMySafeQueue(my_safe_thread *queue, int capacity);

/**
 * 入队
 * @param queue
 * @param item
 */
void enqueueMySafeQueue(my_safe_thread *queue, int item);

int dequeueMySafeQueue(my_safe_thread *queue);

#endif //LH_MYSAFETHREAD_H
