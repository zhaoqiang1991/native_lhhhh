//
// Created by lh on 2023-05-23.
//
#include "SafeThread.h" // 包含队列相关函数的声明

// 在此文件中使用 extern 关键字进行声明，告知编译器这些函数是在其他文件中定义的
extern void initQueue(Queue *queue, int capacity) {
    queue->buffer = (int *) malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->size = 0;
    queue->front = 0;
    queue->rear = -1;
    pthread_mutex_init(&(queue->lock), NULL);
}

extern void enqueue(Queue *queue, int item) {
    pthread_mutex_lock(&(queue->lock));

    if (queue->size >= queue->capacity) {
        printf("队列已满，无法入队\n");
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity;
        queue->buffer[queue->rear] = item;
        queue->size++;
        printf("入队元素：%d\n", item);
    }

    pthread_mutex_unlock(&(queue->lock));
}

extern int dequeue(Queue *queue) {
    pthread_mutex_lock(&(queue->lock));

    if (queue->size <= 0) {
        printf("队列为空，无法出队\n");
        pthread_mutex_unlock(&(queue->lock));
        return -1;
    } else {
        int item = queue->buffer[queue->front];
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
        printf("出队元素：%d\n", item);
        pthread_mutex_unlock(&(queue->lock));
        return item;
    }
}


