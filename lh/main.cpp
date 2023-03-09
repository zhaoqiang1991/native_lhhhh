#include <iostream>
#include "bean/People.h"
#include "bean/Student.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    People *people = new People(20, "lh");
    people->getPeopleInfo();


    Student student = Student(22, "tom", 121, 22.1);
    student.getStudentInfo();

    return 0;
}