//
// Created by root on 12/12/22.
//

#ifndef CPPTEST_VIRTUAL_FUNCTION_H
#define CPPTEST_VIRTUAL_FUNCTION_H

#include <iostream>

class Base
{
public:
    void BaseFunc() {
        std::cout << "base func" << std::endl;
    }
    virtual void VirtualFunc() {
        std::cout << "Father virtual func" << std::endl;
    }
};
class Child : public Base
{
public:
    void ChildFunc() {
        std::cout << "Child func" << std::endl;
    }
    void VirtualFunc() {
        std::cout << "Child virtual func" << std::endl;
    }
    void ChildSpecial()  {
        std::cout << "Call Child Special Func." << std::endl;
    }
};

void test() {
    Child* pChild = new Child();
// 安全，pBase只能访问Base内定义的成员，而pChild继承了Base的所有成员，故不会出现非法访问
    Base* pBase = pChild;
// 想用pBase访问Child特有函数，可在Base中定义虚函数，然后在子类重写，即实现了父类指针调用子类特有函数
    pBase->VirtualFunc(); // 打印 Call Child Special Func.

    Base* tBase = new Base();
//    Child* tChild = tBase; // 语法错误，不允许的转化
// 语法上允许，但不安全，tChild访问的是Base中不存在的函数时，会出现非法访问，不推荐这么做
    Child* tChild = static_cast<Child*>(tBase);

    tChild -> VirtualFunc();
}

#endif //CPPTEST_VIRTUAL_FUNCTION_H
