#include <iostream>
#include "bean/People.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    People *people = new People(20, "lh");

    people->getPeopleInfo();

    return 0;
}