cmake_minimum_required(VERSION 3.14)
project(lh)

set(CMAKE_CXX_STANDARD 17)

add_executable(native Testc.c bean/Student.cpp bean/Student.h bean/People.cpp
        bean/People.h bean/TemplateAnimal.cpp
        bean/TemplateMethod.cpp bean/TemplateMethod.h c/bean/Dog.c c/bean/Dog.h )