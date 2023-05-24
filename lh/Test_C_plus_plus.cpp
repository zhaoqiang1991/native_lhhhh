//
// Created by lh on 2023-05-24.
//
#include <iostream>

/**
 * 第一个测试C++里面创建线程的方法
 */
void test_method1();

using namespace std;

void *test(void *args) {
    int *result = static_cast<int *>(args);
    cout << "=====传递过来的参数= " << *result << "\n" << endl;
    return 0;
}

int main() {
    cout << "=============测试C++的客户端程序=============" << endl;

    test_method1();
    return 0;
}

void test_method1() {
    pthread_t pthread;
    int i = 10;
    pthread_create(&pthread, 0, test, &i);
    system("read");
}
