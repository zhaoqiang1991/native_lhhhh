//
// Created by lh on 2023-05-24.
//

#ifndef LH_MYSAFEQUEUE_H
#define LH_MYSAFEQUEUE_H
/**
 * typedef定义函数指针，函数指针经常用过回调使用
 * 定义格式如下
 * typedef 函数返回值(* 函数名)(函数参数列表)
 * 注意使用typedef定义的函数指针和typedef定义的别名不一样，这个
 * 一定要注意
 */
typedef void (*Callback)(int *);

class MySafeQueue {
public:
    //回调函数
    Callback callback;

public:
    void setCallback(Callback callback);

    void sync(int *i);
};


#endif //LH_MYSAFEQUEUE_H
