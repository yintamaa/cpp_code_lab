//
// Created by root on 11/10/22.
//

#ifndef CPPTEST_SINGLETON_H
#define CPPTEST_SINGLETON_H

/**** effective c++ ****/
template<typename T>

class singleton {
private:
    static T& GetInstance() {
        static T instance;
        return instance;
    }

    singleton(T&&) = delete;
    singleton(const T&) = delete;
    void operator = (const T&) = delete;
protected:
    singleton() = default;
    virtual ~singleton() = default;
};

#endif //CPPTEST_SINGLETON_H
