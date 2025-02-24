//
// Created by lh on 2023-05-24.
//
#include <iostream>
#include <zconf.h>
#include "utils/MySafeQueue.h"
#include "utils/ThreadSafeQueue.h"
#include "bean/Node.h"

using namespace std;

/**
 * 第一个测试C++里面创建线程的方法
 */
void test_method1();

void test_method2();

void test_method3();

void test_method4();

void test_method5();

typedef void (*FP)(char *s);

void Invoke(char *s);


Node *test_method6(Node *head);

bool test_method7(Node *head);

Node *test_method8(Node *pNode, Node *pNode1);

int test_method9();

using namespace std;

void *test(void *args) {
    int *result = static_cast<int *>(args);
    cout << "=====传递过来的参数= " << *result << "\n" << endl;
    return 0;
}

int main() {
    cout << "=============测试C++的客户端程序=============" << endl;

    //test_method1();
    //test_method2();
    //test_method3();
    // test_method4();
    //test_method5();

    /* Node *head5 = new Node(5, nullptr);
     Node *head4 = new Node(4, head5);
     Node *head3 = new Node(3, head4);
     Node *head2 = new Node(2, head3);
     Node *head1 = new Node(1, head2);
     Node *head0 = new Node(0, head1);
     Node *revertNode = test_method6(head0);
     while (revertNode != nullptr) {
         cout << "当前值" << revertNode->val << "-->";
         revertNode = revertNode->next;
     }
     cout << "打印完毕" << endl;*/






/*    Node *head5 = new Node();
    Node *head4 = new Node(4, head5);
    Node *head3 = new Node(3, head4);
    Node *head2 = new Node(2, head3);
    Node *head1 = new Node(1, head2);
    Node *head0 = new Node(0, head1);
    head5->next = head0;
    bool hasCircle = test_method7(head0);

    cout << "是否有环" << (hasCircle == 1) << "<----";*/

    //test_method8(nullptr, nullptr);

    test_method9();
    return 0;
}

/**
 * linux fork机制
 */
int test_method9() {
    int pid = fork();

    if (pid == -1)
        return -1;

    if (pid) {
        printf("我是父进程 我的pid = %d\n", getpid());
        printf("我是父进程 当前fork的pid = %d\n", pid);
        printf("=====================================\n");
        printf("=====================================\n");
        return 0;
    } else {
        printf("我是子进程 我的pid = %d\n", getpid());
        printf("我是子进程 当前fork的pid = %d\n", pid);
        return 0;
    }
}

/**
 * 判断两个链表是否相交
 * @param pNode
 * @param pNode1
 * @return
 */
Node *test_method8(Node *pNode, Node *pNode1) {
    if (pNode == nullptr || pNode1->next == nullptr || pNode1 == nullptr || pNode1->next == nullptr) {
        return nullptr;
    }

    Node *pa = pNode;
    Node *pb = pNode1;
    while (pa != pb) {
        pa = pa == nullptr ? pb : pa->next;
        pb = pb == nullptr ? pa : pb->next;
    }
    return pa;
}

/**
 * 判断一个链表是否又环
 */
bool test_method7(Node *head) {
    Node *slow = head;
    Node *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;

}

Node *test_method6(Node *head) {
    //单链表反转
    Node *next = nullptr;
    Node *pre = nullptr;
    Node *cur = head;

    if (cur == nullptr || cur->next == nullptr) {
        return cur;
    }
    while (cur != nullptr) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;

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
    //auto *mySafeQueue = new MySafeQueue<int>();
    /*  MySafeQueue<int> mySafeQueue;
      int i = 10000;*/
    //mySafeQueue.setCallback(getData);
    //bool isFull = mySafeQueue.checkQueueIsFull(&i);
    // cout << "队列是否满了isFull = " << isFull << endl;
    //delete mySafeQueue;

    ThreadSafeQueue<int> *intQueue = new ThreadSafeQueue<int>();
    intQueue->enqueue(1);
    intQueue->enqueue(2);
    intQueue->enqueue(3);

    while (!intQueue->isEmpty()) {
        cout << intQueue->front() << " ";
        intQueue->dequeue();
    }
    cout << endl;

    ThreadSafeQueue<string> stringQueue;
    stringQueue.enqueue("Hello");
    stringQueue.enqueue("World");
    stringQueue.enqueue("!");

    while (!stringQueue.isEmpty()) {
        cout << stringQueue.front() << " ";
        stringQueue.dequeue();
    }
    cout << endl;
}

void test_method3() {
    FP fp;      //通常是用宏FP来声明一个函数指针fp
    fp = Invoke;
    fp("Hello World!\n");
}

void Invoke(char *s) {
    cout << "C++函数调用测试 s = " << s << endl;
}

void test_method5() {
    MySafeQueue<int> intQueue;
    int a = 4;
    int *b = &a;
    /* intQueue.push(1);
     intQueue.push(2);
     intQueue.push(3);*/
    intQueue.setWork(1);
    intQueue.push(a);


    /* while (!intQueue.isEmpty()) {
         cout << intQueue.front() << " ";
         intQueue.dequeue();
     }*/
    intQueue.pop(b);
    cout << endl;
/*
    MySafeQueue<string> stringQueue;
    stringQueue.push("Hello");
    stringQueue.push("World");
    stringQueue.push("!");

    while (!stringQueue.isEmpty()) {
        cout << stringQueue.front() << " ";
        stringQueue.dequeue();
    }
    cout << endl;*/
}
