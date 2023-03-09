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
    /*  list<int> pList;
      pList.push_front(1);
      pList.push_front(2);
      pList.push_front(3);

      for (list<int>::iterator i = pList.begin(); i != pList.end(); i++) {
          std::cout << "result = " << *i << std::endl;
      }*/

    list<People> data;
    People *p1People = new People(1, "张三");
    People *p2People = new People(2, "李四");
    People *p3People = new People(3, "王五");

    data.push_front(*p1People);
    data.push_front(*p2People);
    data.push_front(*p3People);

    for (list<People>::iterator i = data.begin(); i != data.end(); i++) {
        std::cout << "result = " << "name = " << (*i).getName() + "age = " << i->getAge() << std::endl;
    }
}

void People::getPeopleMapInfo() {
    map<int, People> mp;
    People *p1People = new People(1, "张三");
    People *p2People = new People(1, "张三");
    People *p3People = new People(1, "李四");
    People *p4People = new People(1, "王五");
    mp.insert(pair<int, People>(01, *p1People));
    mp.insert(pair<int, People>(02, *p2People));
    mp.insert(pair<int, People>(03, *p3People));
    mp.insert(pair<int, People>(04, *p4People));


    for (map<int, People>::iterator it = mp.begin(); it != mp.end(); it++) {
        std::cout << "====== result = ""it->first = " << it->first << " = 名字 = " << ((*it).second).toString()
                  << std::endl;


    }
}

string People::toString() {
    std::cout << "age = " << age << " name = " << name << std::endl;
    return std::string();
}
