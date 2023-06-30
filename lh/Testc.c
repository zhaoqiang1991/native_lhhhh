//
// Created by lh on 2023-03-10.
//
#include <stdio.h>
#include <stdlib.h>
#include "c/bean/Dog.h"
#include "utils/SafeThread.h"
#include "utils/MySafeThread.h"

#include <string.h>


void test_method1();

void test_method2();


void *test_method3(int *it, int *num);

void test_method4();

void test_method5();

void test_method6();

void test_method7();

void test_method8();

void test_method9();

void test_method10();

void test_method11();

void test_method12();

void test_method13();

void test_method14();


void function_no_change_string_point(char *p);

void function_no_change_string_point2(char *p);

void function_change_string_point(char **p);

int add(const int *a, const int *b);

int stb(int a, int b);


/**
 * 函数指针
 * @return
 */

int (*caculate)(int *, int *);

void (*subtraction)(int *, int *);


/**
 * 指针函数
 */

int *multy(const int *a, const int *b);

void test_method16();

void test_method17();

mbs *sc = NULL;
ap *p = NULL;

int divResult(int *a, int *b) {
    return *a / *b;
}


int main() {
    //test_method1();
    //test_method2();
    //test_method4();
    //test_method5();
    //test_method6();
    //test_method7();
    //test_method8();
    //test_method9();
    //test_method10();
    //test_method11();
    //test_method12();
    //test_method13();
    //test_method14();
    //test_method16();
    test_method17();

    return 0;
}

void test_method1() {
    int a = 2, b = 6;
    printf("%d\n", max(&a, &b));

    bool c = false;
    printf("%d\n", c);

    int p = 100;
    printf("%d\n", sum(&p));
}

void test_method2() {
    sc = malloc(sizeof(sc));
    int i = 10;
    sc->age = &i;
    eat(sc->age);
    printf("%d\n ", *(sc->age));

}

void *test_method3(int *it, int *num) {
    if (*it > *num) {
        return it;
    }
    return num;
}

void test_method4() {
    int *p, a1 = 2, a2 = 3;
    p = test_method3(&a1, &a2);
    printf("%d\n", *p);
}

//函数指针的使用
void test_method5() {
    int a1 = 2, a2 = 4;
    getInfo = min;
    int i = getInfo(&a1, &a2);
    printf("%d\n", i);
}

void test_method6() {
    int a1 = 3, a2 = 4, *p = 0;
    p = mult(&a1, &a2);
    printf("===%d\n", *p);
}


/**
 * union练习,union同一个时间只能有一个使用，更节省内存
 */

void test_method7() {
    p = malloc(sizeof(p));
    //p->name = 'p';
    p->weight = 3;
    //p->address = (char*) malloc(sizeof(char) * 200);
    if (p == NULL) {
        printf("内存分配失败!");
        return;
    }

/* strcpy(p->address, "刘欢测试C语言字符串！");
     strcat(p->address, "在地址里面追加一些数据");*/

    //printf("%c\n",p->name);
    printf("%s\n", p->address);
    printf("%d\n", p->weight);
    printf("%s\n", "=========================\n");
    free(p);

}

void test_method9() {
    Employee *emp = (Employee *) malloc(sizeof(Employee));

    if (emp == NULL) {
        printf("内存分配失败\n");
        return;
    }

    emp->id = 1;
    strcpy(emp->name, "John Doe");
    strcat(emp->name, "追加数据");
    emp->salary = 5000.0;

    printf("员工ID: %d\n", emp->id);
    printf("员工姓名: %s\n", emp->name);
    printf("员工薪水: %.2f\n", emp->salary);

    free(emp);
}

void test_method8() {
    char arr[30] = "hello world";//初始化字符串
    char arr1 = 'h';//初始化字符串
    char *p;//定义一个指针p
    p = arr;//字符串的地址赋给p
    arr[1] = 'p';
    printf("%s\n", arr);
}


/**
 * 函数指针的简单使用方法
 */

void test_method10() {
    int a = 2, b = 3;
    printf("测试a+b = %d\n", add(&a, &b));
    printf("==========================\n");
    caculate = add;
    int c = 20, d = 3;

    printf("测试函数指针c+d = %d\n", caculate(&c, &d));
    printf("==========================\n");
    int result = (int) multy(&c, &d);
    printf("测试指针函数c*d = %d\n", result);

}

int add(const int *a, const int *b) {
    return *a + *b;
}

int *multy(const int *a, const int *b) {
    return (*a) * (*b);
}

int stb(int a, int b) {
    return a - b;
}

void test_method11() {
    int a = 9, b = 5;

    printf("a - b的值 = %d\n", caculateResult(stb, a, b));

}

void test_method12() {
    int a = 10, b = 5;

    printf("a / b的值 = %d\n", caculateResultOther(divResult, &a, &b));
}

int caculateResult(int (*operation)(int, int), int c, int d) {
    return operation(c, d);
}

int caculateResultOther(pFunction operation, int *c, int *d) {
    return operation(c, d);
}


void test_method13() {
    Queue queue;
    int capacity = 5;

    initQueue(&queue, capacity);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    for (int i = 0; i < queue.capacity; ++i) {
        dequeue(&(queue));
    }

    free(queue.buffer);
    pthread_mutex_destroy(&(queue.lock));

}

void test_method14() {
    my_safe_thread mySafeThread;
    int capacity = 5;
    initMySafeQueue(&mySafeThread, capacity);
    for (int i = 0; i < capacity; i++) {
        enqueueMySafeQueue(&mySafeThread, i);
    }
    printf("======================================================\n\n");

    for (int i = 0; i < capacity; i++) {
        dequeueMySafeQueue(&mySafeThread);
    }
    printf("mySafeThread.size= %d\n\n", mySafeThread.size);
    free(mySafeThread.buffer);
    pthread_mutex_destroy(&mySafeThread.lock);

}


void test_method16() {/**
 * 1.使用c语言的指针地址修改的特点，我们可以在一个函数中直接修改这个变量的地址，并为其初始化内容（有点像构造函数）

2.修改内存地址的指向需要比原来更高一级的指针传递到函数中，然后在函数中修改即可

3.使用这个方式就可以修改数组的内存地址了

 */
    //char *p = malloc(sizeof(char) * 10);
    char  *p = NULL;
    p = "123456"; // 将p指向123456
    printf("p==>%s\n", p);
    // 无法改变一个指针
    function_no_change_string_point(&p);
    printf("p==>%s\n", p);
    // 改变一个指针直接传递比原来指针多一级的指针即可
    function_change_string_point(&p);
    printf("p==>%s\n", p);
}


void test_method17() {
    /**
     * 传递地址可以修改指针的值这个和test_method16里面的测试要区别开来，不要混淆了
     */
    //char *p = malloc(sizeof(char) * 10);
    char  *p = NULL;
    p = "123456"; // 将p指向123456
    printf("p==>%s\n", p);
    // 无法改变一个指针
    function_no_change_string_point2(&p);
    printf("p==>%s\n", p);
    // 改变一个指针直接传递比原来指针多一级的指针即可
    function_change_string_point(&p);
    printf("p==>%s\n", p);
}

void test_method15(int *p) {
    *p = 20;
}

void function_change_string_point(char **p) {
    *p = "666666";
}


void function_no_change_string_point(char *p) {
    p = "888888";
}

void function_no_change_string_point2(char *p) {
    *p = "888888";
}
