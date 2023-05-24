//
// Created by lh on 2023-05-24.
//

#include "MySafeThread.h"

void initMySafeQueue(my_safe_thread *queue, int capacity) {
    //申请内存空间
    queue->buffer = (int *) malloc(sizeof(int) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    //队尾指针
    queue->rear = -1;
    //初始化锁
    pthread_mutex_init(&(queue->lock), 0);
}

void enqueueMySafeQueue(my_safe_thread *queue, int item) {
    //加锁
    pthread_mutex_lock(&queue->lock);
    if (queue->size >= queue->capacity) {
        printf("========= 队列已经满了!!!");
    } else {
        //计算队列的尾指针位置
        queue->rear = (queue->rear + 1) % queue->capacity;
        //存放新加入的元素到队列尾部
        queue->buffer[queue->rear] = item;
        //队列大小+1
        queue->size++;
        printf("========= 队列元素 = %d,队列大小= %d\n", item,queue->size);
    }
    //释放锁
    pthread_mutex_unlock(&queue->lock);
}

/**
 * 出队列
 * @param queue
 * @return
 */
int dequeueMySafeQueue(my_safe_thread *queue) {
    pthread_mutex_lock(&queue->lock);
    if (queue->size <= 0) {
        printf("========= 队列为空!!!");
        //释放锁
        pthread_mutex_unlock(&queue->lock);
        return 0;
    } else {
        //取出元素
        int item = queue->buffer[queue->front];
        //队首指针向上移动一次
        queue->front = (queue->front + 1) % queue->capacity;
        queue->size--;
        printf("========= 出队列元素 = %d,队列的大小=%d \n", item,queue->size);
        //释放锁
        pthread_mutex_unlock(&queue->lock);
        return item;
    }
}
