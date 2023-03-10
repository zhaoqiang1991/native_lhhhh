#include <iostream>
#include "bean/People.h"
#include "bean/Student.h"

#include <list>
#include "bean/TemplateAnimal.cpp"
#include "bean/TemplateMethod.cpp"
//c/c++都有一个习惯就是先声明函数，然后在实现函数，有这个规则，标准

void test_method1();

void test_unique_ptr();

void test_template();

void test_templateMethod();

void test_virtualStanicBindMethod();

void test_virtualDynamicBindMethod();

void test_lambdaMethod();


int main() {
    //test_method1();

    //test_unique_ptr();
    //test_template();
    //test_templateMethod();
    //test_virtualStanicBindMethod();
    //test_virtualDynamicBindMethod();
    test_lambdaMethod();
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

void test_template() {
    auto *pAnimal = new TemplateAnimal(People(1212, "bill"));
    auto *people = new People(1912, "chanle");
    pAnimal->setAddress(*people);

    auto pTemplateAnimal = new TemplateAnimal(string("北京市海淀区中关村"));

    cout << "======pAnimal->getAddress() = " << (pAnimal->getAddress().toString()) << endl;
    cout << "======pAnimal->getAddress() = " << (pTemplateAnimal->getAddress()) << endl;


}

void test_templateMethod() {
    TemplateMethod methon;
    int a = 1;
    int b = 2;
    cout << "==== swip = " << methon.swip(a, b) << endl;
}

//这种属于静态绑定，就是在编译的时候已经决定了类型
void test_virtualStanicBindMethod() {

    People addr, *pPeople;//= new People(1, "pppp");
    Student student;
    pPeople = &addr;

    pPeople->eat();
    pPeople = &student;
    pPeople->eat();

    People *p = new Student;
    p->eat();

}

//动态绑定,在运行期间决定类型
void test_virtualDynamicBindMethod() {

    People addr, *pPeople;//= new People(1, "pppp");
    Student student;
    pPeople = &addr;

    pPeople->eat();
    pPeople = &student;
    pPeople->eat();

    People *p = new Student;
    p->eat();
}

void test_lambdaMethod() {
    auto f1 = [](int it, int num) -> int { return (it + num); };
    cout << "======" << f1(2, 3) << endl;

    auto f = [](int a) -> int { return a + 1; };
    std::cout << "=======" << f(1) << std::endl;

    auto f2 = [](const int *it, const int *num) -> int { return (*it + *num); };

    int i = 3, k = 4;
    cout << "=======" << f2(&i, &k) << endl;
}


