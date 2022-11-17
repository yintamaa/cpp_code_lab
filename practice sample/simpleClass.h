//
// Created by root on 11/14/22.
//

#ifndef CPPTEST_SIMPLECLASS_H
#define CPPTEST_SIMPLECLASS_H

class simpleClass {
private:
    const int const_variable;
    int variable;
    static int static_variable;
public:
    simpleClass() = default;
    static void static_function();
};

#endif //CPPTEST_SIMPLECLASS_H
