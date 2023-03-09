//
// Created by lh on 2023-03-09.
//

#include "Student.h"

Student::~Student() {

}

Student::Student(int age, const string &name, int num, float score) : People(age, name), num(num), score(score) {
    std::cout << "====学生有参构造函数 num = " << num << " score = " << score << std::endl;
}

void Student::getStudentInfo() {
    std::cout << "====getStudentInfo" << std::endl;

}
