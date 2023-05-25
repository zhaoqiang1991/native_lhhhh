//
// Created by lh on 2023-05-24.
//

#include "MySafeQueue.h"


void MySafeQueue::setCallback(Callback callback) {
    this->callback = callback;
}

void MySafeQueue::sync(int *i) {
    callback(i);
}
