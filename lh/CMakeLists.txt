cmake_minimum_required(VERSION 3.14)
project(lh)

set(CMAKE_CXX_STANDARD 17)

#在同一个CMakeList管理的项目中，不能有两个main方法的文件，否则会变异报错，如果想有多个main方法
#可以放在不同的module使用CMakeList管理起来
add_executable(native #[[Testc.c]]
        bean/Student.cpp
        bean/Student.h
        bean/People.cpp
        bean/People.h
        bean/TemplateAnimal.cpp
        bean/TemplateMethod.cpp
        bean/TemplateMethod.h
        c/bean/Dog.c
        c/bean/Dog.h
        utils/SafeThread.c
        utils/SafeThread.h
        utils/MySafeThread.c
        utils/MySafeThread.h
        utils/MySafeQueue.cpp
        utils/MySafeQueue.h
        Test_C_plus_plus.cpp)