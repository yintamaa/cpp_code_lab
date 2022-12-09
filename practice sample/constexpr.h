//
// Created by root on 12/8/22.
//

#ifndef CPPTEST_CONSTEXPR_H
#define CPPTEST_CONSTEXPR_H

#include <vector>
#include <map>
typedef std::map<int, std::map<int, int>> mp;

class constExpr
{
static constexpr int a = 100;

constexpr static int b = 100; // 类内一定要加static，因为constexpr是编译期



};


#endif //CPPTEST_CONSTEXPR_H
