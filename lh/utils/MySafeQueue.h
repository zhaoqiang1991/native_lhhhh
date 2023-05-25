//
// Created by lh on 2023-05-24.
//

#ifndef LH_MYSAFEQUEUE_H
#define LH_MYSAFEQUEUE_H

#include <queue>
#include <pthread.h>
#include <iostream>

using namespace std;

/**
 * typedef定义函数指针，函数指针经常用过回调使用
 * 定义格式如下
 * typedef 函数返回值(* 函数名)(函数参数列表)
 * 注意使用typedef定义的函数指针和typedef定义的别名不一样，这个
 * 一定要注意，使用函数指针定义的回调方法，外面调用的时候，就是
 * 直接使用函数名(参数)就可以了，其实有点类似java的接口回调
 * 其实语言看多了，他们的内部原理都是类似的，都是相互借鉴
 *
 * C++中模板的实现确实需要放在头文件中。由于模板的特性，编译器需要在编
 * 译阶段生成特定类型的模板实例化代码。如果将模板的声明和实现分离，链接器
 * 在链接阶段无法找到具体的模板实例化代码，从而导致链接错误。因此，正确的
 * 做法是将类模板的声明和实现部分放在同一个头文件中，并将该头文件包含在需
 * 要使用模板的源文件中。这样可以确保编译器在需要的地方生成模板实例化代码。
 */
template<typename T>

/**
 * C++的类声明和Java其实很类似，都是按照，先定义属性，然后定义构造方法，析构方法，最后就是定义
 * 各种方法，按照这个顺序
 * @tparam T
 */
class MySafeQueue {
    typedef void (*Callback)(int *);

    /**
     * 释放一些数据接口
     */
    typedef void (*ReleaseCallback)(T *);

    typedef void (*SyncHandler)(T *);

public:
    //回调函数
    Callback callback;
    //队列存放数据
    queue<T> q;

    ReleaseCallback releaseCallback;

    SyncHandler syncHandler;

    /**
     * posix线程锁
     */
    mutable pthread_mutex_t lock;
    /**
     * posix线程通信条件
     */
    pthread_cond_t cond;

    /**
     * 队列是否工作的标记，1：工作，0：不可以工作
     */
    int work;


public:
    MySafeQueue() {
        //初始化锁
        pthread_mutex_init(&lock, 0);
        pthread_cond_init(&cond, 0);
    }

    ~MySafeQueue() {
        pthread_mutex_destroy(&lock);
        pthread_cond_destroy(&cond);
    }

    void setCallback(Callback callback) {
        callback = callback;
    }

    void sync() {
        pthread_mutex_lock(&lock);
        syncHandler(q);
        pthread_mutex_unlock(&lock);
    }

    /**
     * 入队操作
     */
    void push(T new_value) {
        pthread_mutex_lock(&lock);
        if (work) {
            q.push(new_value);
            //通知可以取数据了
            pthread_cond_signal(&cond);
        }
        pthread_mutex_unlock(&lock);
    }

    void dequeue() {
        pthread_mutex_lock(&lock);
        if (!q.empty()) {
            q.pop();
        }
        pthread_mutex_unlock(&lock);
    }

    T front() const {
        pthread_mutex_lock(&lock);
        T value = q.front();
        pthread_mutex_unlock(&lock);
        return value;
    }

    /**
     * 出队操作
     * @return
     */
    bool pop(T *value) {
        pthread_mutex_lock(&lock);
        int success = 0;
        //while (work && q.empty()) {
        //队列是工作状态，但是目前队列是空的，也就是没有数据的状态,那么就等待队列有
        //新的数据,就一直等待在这里，那么程序也就不会继续的向下走，也就是卡在这里
        // pthread_cond_wait(&cond, &lock);
        //}
        if (!q.empty()) {
            //队列有数据了，此时就不会卡在上面了，就会走下来
            T value = q.front();
            cout << "出队元素 value= " << value << " ";
            //队首指针向上移动一下
            q.pop();
            success = 1;
        }
        pthread_mutex_unlock(&lock);
        return success;
    }

    void setWork(int work) {
        pthread_mutex_lock(&lock);
        MySafeQueue::work = work;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&lock);
    }

    /**
     * 队列大小
     * @return
     */
    int size() {
        pthread_mutex_lock(&lock);
        int size = q.size();
        pthread_mutex_unlock(&lock);
        return size;
    }

    bool isEmpty() {
        pthread_mutex_lock(&lock);
        bool empty = q.empty();
        pthread_mutex_unlock(&lock);
        return empty;
    }

    void clear() {
        pthread_mutex_lock(&lock);
        int size = q.size();
        for (int i = 0; i < size; i++) {
            T t = q.front();
            releaseCallback(&t);
            q.pop();
        }
        pthread_mutex_unlock(&lock);
    }

    bool checkQueueIsFull(int *i) {
        callback(i);
        return *i == 1;
    }
};


#endif //LH_MYSAFEQUEUE_H
