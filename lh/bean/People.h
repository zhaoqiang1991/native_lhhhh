//
// Created by lh on 2023-03-09.
//

#ifndef LH_PEOPLE_H
#define LH_PEOPLE_H

#include <string>
#include <iostream>

using namespace std;
class People {
public:
    People(int age, const string &name);

    virtual ~People();

    int getAge() const;

    void setAge(int age);

    const string &getName() const;

    void setName(const string &name);

    void getPeopleInfo();

private:
    int age;
    string name;

};


#endif //LH_PEOPLE_H
