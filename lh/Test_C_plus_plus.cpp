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

class ProgramA {
public:
    void FunA1() { printf("I'am ProgramA.FunA1() and be called..\n"); }

    void FunA2() { printf("I'am ProgramA.FunA2() and be called..\n"); }
};

class ProgramB {
public:
    void FunB1(void (ProgramA::*callback)(), void *context) {
        printf("I'am ProgramB.FunB1() and be called..\n");
        ((ProgramA *) context->*callback)();
    }
};


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

void aaa(int *i) {
    cout << "C++函数调用测试 i = " << *i << endl;
}


void test_method2() {
    MySafeQueue mySafeQueue;
    int i = 10000;
    mySafeQueue.setCallback(aaa);
    mySafeQueue.sync(&i);
}

void test_method3() {
    FP fp;      //通常是用宏FP来声明一个函数指针fp
    fp = Invoke;
    fp("Hello World!\n");
}

void Invoke(char *s) {
    cout << "C++函数调用测试 s = " << s << endl;
}

void test_method4() {
    ProgramA PA;
    PA.FunA1();

    ProgramB PB;
    PB.FunB1(&ProgramA::FunA2, &PA);
}
