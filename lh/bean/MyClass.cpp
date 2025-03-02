#include <iostream>
#include <memory>
#include <atomic>

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor" << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass Destructor" << std::endl;
    }

    void onFirstRef() {
        std::cout << "onFirstRef() called: First strong reference acquired" << std::endl;
    }
};

// 自定义智能指针管理类
class SmartPointer {
private:
    std::shared_ptr<MyClass> ptr;
    std::atomic<bool> firstRefCalled{false};

public:
    SmartPointer(MyClass* obj) : ptr(obj, [this](MyClass* p) {
        delete p;
        std::cout << "Custom deleter called" << std::endl;
    }) {
        if (!firstRefCalled.exchange(true)) {
            ptr->onFirstRef(); // 只在第一个引用创建时调用
        }
    }

    std::shared_ptr<MyClass> get() {
        return ptr;
    }
};
/*

int main() {
    std::cout << "Creating SmartPointer..." << std::endl;
    SmartPointer smartPtr(new MyClass());
    std::shared_ptr<MyClass> ptr1 = smartPtr.get(); // onFirstRef() 触发

    {
        std::cout << "Creating another shared_ptr..." << std::endl;
        std::shared_ptr<MyClass> ptr2 = ptr1; // 共享引用，不触发 onFirstRef()
    } // ptr2 作用域结束

    std::cout << "Exiting main, last reference gone..." << std::endl;
    return 0;
}
*/
