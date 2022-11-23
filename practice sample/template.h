//
// Created by root on 11/17/22.
//

#ifndef CPPTEST_TEMPLATE_H
#define CPPTEST_TEMPLATE_H

#include <iostream>

// 函数模板
template <typename T>
inline T const& add(T &a, T &b) {
    return a + b;
}

// 类模板，支持默认类型设置，
template <class k, class v = int>
class Item {
private:
    k key;
    v value;
public:
    Item(k key, v value) {
        this->key = key;
        this-> value = value;
    }
};

template <class T1, class T2>
class Pair {
private:
    T1 key;
    T2 value;
public:
    Pair(T1 key, T2 value):key(key),value(value){};
    bool operator < (const Pair<T1,T2> &x) const {
        if (key != x.key) return key < x.key;
        else return value < x.value;
    }
};

void templateTest() {
    Item<int>item1(123,456); // 使用默认类型
    Item<int, std::string>item2(123,"456"); // 使用动态类型
    Item<int,std::string> *item3 = new Item<int,std::string>(123, "456");

}
#endif //CPPTEST_TEMPLATE_H
