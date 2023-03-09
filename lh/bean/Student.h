//
// Created by lh on 2023-03-09.
//

#ifndef LH_STUDENT_H
#define LH_STUDENT_H


#include "People.h"
#include <iostream>

using namespace std;

class Student : public People {
public:
    Student(int age, const string &name, int num, float score);

    virtual ~Student();

    void getStudentInfo();

private:

    int num;
    float score;
};


#endif //LH_STUDENT_H
