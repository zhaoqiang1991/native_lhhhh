//
// Created by lh on 2023-03-09.
//

#ifndef LH_PEOPLE_H
#define LH_PEOPLE_H

#include <string>
#include <iostream>
#include <list>
#include <map>
#include <set>

using namespace std;

class People {
public:
    People();

    People(int age, const string &name);

    virtual ~People();

    int getAge() const;

    void setAge(int age);

    const string &getName() const;

    void setName(const string &name);

    void getPeopleInfo();

    void getPeopleMapInfo();

    string toString();

    void getPeopleSetInfo();

    //放在set容器里面必须重写 比较操作
    bool operator<(const People &y) const//重载运算符，很重要
    {
        return (this->age < y.age
                || this->name == y.name);
    }


    virtual void eat();


private:
    int age;
    string name;

public:
    shared_ptr<People> ptr;
};


#endif //LH_PEOPLE_H
