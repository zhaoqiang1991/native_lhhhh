//
// Created by lh on 2023-05-24.
//
#include <iostream>
#include "utils/MySafeQueue.h"

/**
 * 第一个测试C++里面创建线程的方法
 */
void test_method1();

void test_method2();

void test_method3();

void test_method4();

typedef void (*FP)(char *s);

void Invoke(char *s);


using namespace std;

void *test(void *args) {
    int *result = static_cast<int *>(args);
    cout << "=====传递过来的参数= " << *result << "\n" << endl;
    return 0;
}

int main() {
    cout << "=============测试C++的客户端程序=============" << endl;

    //test_method1();
    test_method2();
    //test_method3();
    // test_method4();
    return 0;
}

void test_method1() {
    pthread_t pthread;
    int i = 10;
    pthread_create(&pthread, 0, test, &i);
    system("read");
}

void getData(int *i) {
    cout << "C++函数调用测试 i = " << *i << endl;
}


void test_method2() {
    //堆栈申请的内存需要手动释放,不然会内存泄露
    MySafeQueue *mySafeQueue = new MySafeQueue();
    int i = 10000;
    mySafeQueue->setCallback(getData);
    mySafeQueue->sync(&i);
    delete mySafeQueue;
}

void test_method3() {
    FP fp;      //通常是用宏FP来声明一个函数指针fp
    fp = Invoke;
    fp("Hello World!\n");
}

void Invoke(char *s) {
    cout << "C++函数调用测试 s = " << s << endl;
}
