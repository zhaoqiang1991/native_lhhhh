//
// Created by lh on 2023-03-09.
//

#include "People.h"


People::~People() {
    std::cout << "======= 无参构造函数" << std::endl;
}


People::People(int age, const string &name) : age(age), name(name) {
    std::cout << "======= 有参构造函数" << "age = " << age << "name = " << name << std::endl;

}

int People::getAge() const {
    return age;
}

void People::setAge(int age) {
    People::age = age;
}

const string &People::getName() const {
    return name;
}

void People::setName(const string &name) {
    People::name = name;
}

void People::getPeopleInfo() {
    std::cout << "======= getPeopleInfo" << std::endl;
    list<int> pList;
    pList.push_front(1);
    pList.push_front(2);
    pList.push_front(2);

    for (list<int>::iterator i = pList.begin(); i != pList.end(); i++) {
        std::cout << "result = " << *i << std::endl;
    }

}
