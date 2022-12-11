//
// Created by root on 12/12/22.
//

#ifndef CPPTEST_CLASS_FUNCTION_H
#define CPPTEST_CLASS_FUNCTION_H

#include <iostream>

class ClassFunction {
private:
    int *data_;
public:
    std::string name_;
    ClassFunction(const int n) {
        data_ = new int[n];
        std::cout << "construct" << std::endl;
    }
    // 移动构造函数
    ClassFunction(ClassFunction &&obj):data_(obj.data_) {
        obj.data_ = nullptr;
        std::cout << "move construct" << std::endl;
    }
    // 拷贝构造函数
    ClassFunction(const ClassFunction& obj):data_(new int(*obj.data_)) {
        std::cout << "copy construct" << std::endl;
    }
    // 右值拷贝
    ClassFunction& operator=(const ClassFunction &&x) {
        std::cout << "copy rvalue" << std::endl;
        data_ = x.data_;
        return *this;
    }
    // 左值拷贝
    ClassFunction& operator=(const ClassFunction &x) {
        std::cout << "copy lvalue" << std::endl;
        data_ = new int(*x.data_);
        return *this;
    }
    ~ClassFunction() {
        std::cout << "class destruct " << name_ << std::endl;
    }
};

ClassFunction construct() {
    return ClassFunction(100);
}

void test() {
    ClassFunction a = construct(); // 调用移动构造函数
    a.name_ = "a";
    ClassFunction b = a; // 调用拷贝构造函数，a是左值
    b.name_ = "b";
    ClassFunction c = std::move(b); // 调用移动构造函数
    c.name_ = "c";
    ClassFunction d(100);
    d = c; // 左值拷贝
    d.name_ = "d";
    d = std::move(c); // 右值拷贝
    return ;
}

#endif //CPPTEST_CLASS_FUNCTION_H
