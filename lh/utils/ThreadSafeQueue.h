#ifndef THREADSAFEQUEUE_H
#define THREADSAFEQUEUE_H

#include <queue>
#include <pthread.h>
#include <iostream>

using namespace std;

template<typename T>
class ThreadSafeQueue {
public:
    ThreadSafeQueue() {
        pthread_mutex_init(&mutex, nullptr);
    }

    ~ThreadSafeQueue() {
        pthread_mutex_destroy(&mutex);
    }

    void enqueue(const T &value) {
        pthread_mutex_lock(&mutex);
        queue.push(value);
        cout << "队列大小= " << queue.size() << " ";
        pthread_mutex_unlock(&mutex);
    }

    void dequeue() {
        pthread_mutex_lock(&mutex);
        if (!queue.empty()) {
            queue.pop();
        }
        pthread_mutex_unlock(&mutex);
    }

    T front() const {
        pthread_mutex_lock(&mutex);
        T value = queue.front();
        pthread_mutex_unlock(&mutex);
        return value;
    }

    bool isEmpty() const {
        pthread_mutex_lock(&mutex);
        bool empty = queue.empty();
        pthread_mutex_unlock(&mutex);
        return empty;
    }

    size_t size() const {
        pthread_mutex_lock(&mutex);
        size_t queueSize = queue.size();
        pthread_mutex_unlock(&mutex);
        return queueSize;
    }

private:
    std::queue<T> queue;
    mutable pthread_mutex_t mutex;
};

#endif  // THREADSAFEQUEUE_H
