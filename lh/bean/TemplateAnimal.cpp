//
// Created by lh on 2023-03-10.
//

#include <string>
#include <iostream>

#ifndef LH_TEMPLATEANIMAL_CPP
#define LH_TEMPLATEANIMAL_CPP
using namespace std;

//模板类只能定义在cpp源文件中，不可以定义到头文件中
template<typename T>



class TemplateAnimal {


public:
    TemplateAnimal(T address) : address(address) {
        //cout << "===== TemplateAnimal 构造函数" << address << endl;
    }

    TemplateAnimal() {}

    virtual ~TemplateAnimal() {

    }

public:
    void setAddress(T address) {
        TemplateAnimal::address = address;
    }

    T getAddress() {
        return address;
    }

private:
    T address;
};


#endif //LH_TEMPLATEANIMAL_CPP
