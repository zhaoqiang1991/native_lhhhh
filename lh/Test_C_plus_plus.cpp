//
// Created by lh on 2023-05-24.
//
#include <iostream>
#include <zconf.h>
#include <semaphore.h>
#include "utils/MySafeQueue.h"
#include "utils/ThreadSafeQueue.h"
#include "bean/Node.h"
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cstring>
#include <cerrno>
#include "bean/MyClass.cpp"

#define SHARED_MEMORY_SIZE 4096  // 共享内存大小，4KB


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

void test_method10();

void test_method11();

void test_method12();

void test_method13();

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

    /* test_method9();*/
    //test_method10();
    //test_method11();
   /* test_method12();*/

    test_method13();
    return 0;
}

void test_method13() {
    std::cout << "Creating SmartPointer..." << std::endl;
    SmartPointer smartPtr(new MyClass());
    std::shared_ptr<MyClass> ptr1 = smartPtr.get(); // onFirstRef() 触发

    {
        std::cout << "Creating another shared_ptr..." << std::endl;
        std::shared_ptr<MyClass> ptr2 = ptr1; // 共享引用，不触发 onFirstRef()
    } // ptr2 作用域结束

    std::cout << "Exiting main, last reference gone..." << std::endl;
}

/**
 * 匿名内存共享
 */
void test_method12() {
// 创建匿名共享内存
    void *shared_memory = mmap(NULL, SHARED_MEMORY_SIZE, PROT_READ | PROT_WRITE,
                               MAP_ANONYMOUS | MAP_SHARED, -1, 0);

    if (shared_memory == MAP_FAILED) {
        std::cerr << "mmap failed!" << std::endl;
        return;
    }

    pid_t pid = fork();  // 创建子进程

    if (pid == 0) {  // 子进程
        // 子进程修改共享内存中的数据
        char *data = (char *) shared_memory;
        std::strcpy(data, "Hello from child process!，测试代码");
        std::cout << "Child process updated shared memory." << std::endl;
        exit(0);
    } else {  // 父进程
        wait(NULL);  // 等待子进程结束

        // 父进程读取共享内存中的数据
        char *data = (char *) shared_memory;
        std::cout << "Parent process reads: " << data << std::endl;

        // 清理共享内存
        munmap(shared_memory, SHARED_MEMORY_SIZE);
    }
}

void test_method11() {
    int pipefd[2];
    pid_t pid;
    const char *message = "Hello from parent!";

    // 创建管道
    if (pipe(pipefd) == -1) {
        std::perror("pipe");
        exit(1);
    }

    pid = fork();

    if (pid == 0) {  // 子进程（Consumer）
        close(pipefd[1]);  // 关闭写端
        char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer));
        std::cout << "子进程可以写入数据..." << std::endl;
        std::cout << "Child received: " << buffer << std::endl;
        close(pipefd[0]);
        sleep(20);
        exit(0);
    } else {  // 父进程（Producer）
        close(pipefd[0]);  // 关闭读端
        std::cout << "父进程可以写入数据..." << std::endl;
        sleep(4);
        write(pipefd[1], message, strlen(message) + 1);  // 向管道写入数据
        close(pipefd[1]);
        wait(NULL);  // 等待子进程结束
    }
}

sem_t sem;  // 声明信号量
void *producer(void *arg) {
    std::cout << "Producer is running..." << std::endl;
    sleep(20);  // 模拟处理过程，20ms
    sem_post(&sem);  // 生产完成，发出信号
    std::cout << "Producer finished." << std::endl;
    return NULL;
}

void test_method10() {
    pid_t pid;
    pthread_t thread;

    // 初始化信号量
    sem_init(&sem, 1, 0);  // 信号量初始化为 0

    pid = fork();

    if (pid == 0) {  // 子进程（Consumer）
        std::cout << "Consumer is waiting for signal..." << std::endl;
        sem_wait(&sem);  // 等待信号
        std::cout << "Consumer is consuming..." << std::endl;
        std::cout << "Consumer finished." << std::endl;
        exit(0);
    } else {  // 父进程（Producer）
        pthread_create(&thread, NULL, producer, NULL);
        pthread_join(thread, NULL);
        wait(NULL);  // 等待子进程结束
    }

    // 清理资源
    sem_destroy(&sem);
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
