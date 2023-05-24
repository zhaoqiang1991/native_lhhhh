//
// Created by lh on 2023-05-23.
//
#ifndef LH_SAFETHREAD_H
#define LH_SAFETHREAD_H
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* buffer;
    int capacity;
    int size;
    int front;
    int rear;
    pthread_mutex_t lock;
} Queue;

void initQueue(Queue* queue, int capacity);
void enqueue(Queue* queue, int item);
int dequeue(Queue* queue);

#endif
