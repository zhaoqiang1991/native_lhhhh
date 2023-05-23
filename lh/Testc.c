//
// Created by lh on 2023-03-10.
//
#include <stdio.h>
#include <stdlib.h>
#include "c/bean/Dog.h"
#include "utils/SafeThread.h"

/*
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

void test_method12();*/

void test_method13();
/*

int add(const int *a, const int *b);

int stb(int a, int b);


*/
/**
 * 函数指针
 * @return
 *//*

int (*caculate)(int *, int *);

void (*subtraction)(int *, int *);

*/
/**
 * 指针函数
 *//*

int *multy(const int *a, const int *b);

mbs *sc = NULL;
ap *p = NULL;

int divResult(int *a, int *b) {
    return *a / *b;
}
*/

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
    test_method13();
    return 0;
}
/*

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


*/
/**
 * union练习,union同一个时间只能有一个使用，更节省内存
 *//*

void test_method7() {
    p = malloc(sizeof(p));
    //p->name = 'p';
    p->weight = 3;
    //p->address = (char*) malloc(sizeof(char) * 200);
    if (p == NULL) {
        printf("内存分配失败!");
        return;
    }
    */
/* strcpy(p->address, "刘欢测试C语言字符串！");
     strcat(p->address, "在地址里面追加一些数据");*//*

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

*/
/**
 * 函数指针的简单使用方法
 *//*

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
*/


void test_method13() {
    Queue queue;
    int capacity = 5;

    initQueue(&queue, capacity);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    free(queue.buffer);
    pthread_mutex_destroy(&(queue.lock));

}



