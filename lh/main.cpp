#include <iostream>
#include "bean/People.h"
#include "bean/Student.h"

#include <list>
//c/c++都有一个习惯就是先声明函数，然后在实现函数，有这个规则，标准

void test_method1();

void test_unique_ptr();

int main() {
    //test_method1();

    test_unique_ptr();

    return 0;
}

void test_method1() {
    People *people = new People(20, "lh");
    people->getPeopleInfo();
    cout << "============================ \n" << endl;

    people->getPeopleMapInfo();
    cout << "============================ \n" << endl;

    people->getPeopleSetInfo();

    Student student = Student(22, "tom", 121, 22.1);
    student.getStudentInfo();
}

void test_unique_ptr() {
    unique_ptr<People> up(new People(1, "toms"));

    shared_ptr<People> sp(new People(20, "jesson"));

    cout << "=====test_unique_ptr " << up.get() << "  sp.use_count() = " << sp.use_count() << endl;
    cout << "======sp->toString() = " << sp->toString() << endl;


}


