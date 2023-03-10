//
// Created by lh on 2023-03-09.
//

#include "People.h"


People::~People() {
    std::cout << "======= 无参构造函数" << std::endl;
}


People::People(int age, const string &name) : age(age), name(name) {
    std::cout << "======= 有参构造函数" << "age = " << age << "age = " << name << std::endl;

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
        std::cout << "result = " << "age = " << (*i).getName() + "age = " << i->getAge() << std::endl;
    }
}

void People::getPeopleMapInfo() {
    map<int, People> mp;
    auto *p1People = new People(1, "张三");
    auto *p2People = new People(1, "张三");
    auto *p3People = new People(1, "李四");
    auto *p4People = new People(1, "王五");
    mp.insert(pair<int, People>(01, *p1People));
    mp.insert(pair<int, People>(02, *p2People));
    mp.insert(pair<int, People>(03, *p3People));
    mp.insert(pair<int, People>(04, *p4People));


    for (auto &it : mp) {
        std::cout << "====== getPeopleMapInfo result = ""it->first = " << it.first << " = 名字 = "
                  << (it.second).toString()
                  << std::endl;
    }
}

string People::toString() {
    std::cout << "age = " << age << " age = " << name << std::endl;
    return std::string();
}

void People::getPeopleSetInfo() {
    set<People> st;
    People *p1People = new People(1, "张三1");
    auto p2People = new People(10, "张三2");
    auto p3People = new People(19, "李四");
    auto p4People = new People(17, "王五");

    st.insert(*p1People);

    st.insert(*p2People);
    st.insert(*p3People);
    st.insert(*p4People);

    for (const auto &it : st) {
        std::cout << "====== getPeopleSetInfo result = ""it->first = " << it.getName() << std::endl;
    }
}

void People::eat() {
    cout<<"======eat people "<<endl;
}

People::People() {}




