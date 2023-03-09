#include <iostream>
#include "bean/People.h"
#include "bean/Student.h"

#include <list>

int main() {
    std::cout << "Hello, World!" << std::endl;
    People *people = new People(20, "lh");
    people->getPeopleInfo();


    Student student = Student(22, "tom", 121, 22.1);
    student.getStudentInfo();

    /*list<int> it;
    it.push_front(1);
    it.push_front(2);
    it.push_front(3);
    it.push_front(4);
    for (list<int>::iterator i = it.begin(); i != it.end(); i++) {
        std::cout << "========= 遍历数据= " << *i << std::endl;
    }*/


    return 0;
}