//
// Created by Administrator on 2022/12/20.
//

#ifndef CPPTEST_CODE_STYLE_H
#define CPPTEST_CODE_STYLE_H

#include <iostream>
#include <cmath>
#include <algorithm>

constexpr double eps = 1e-15;

int cmp(double x) {
    if (fabs(x) < eps) {
        return 0;
    }
    else if (fabs(x) > 0) {
        return 1;
    } else {
        return -1;
    }
}

struct Di3 {
    double x, y, z;
//    Di3() = default;
    Di3(double x, double y, double z) : x(x), y(y), z(z){}
    Di3 operator - (const Di3 &t) const {
        return Di3(t.x - x, t.y - y, t.z - z);
    }
};

struct point {
    Di3 di3;
    Di3 operator - (const point &x) const {
        return x.di3 - di3;
    }
};

struct vec3 {
    Di3 *di3;
    vec3() = default;
    vec3(point &x, point &y) {
        di3 = new Di3(y - x);
    }
};

class geometry {
public:



};

#endif //CPPTEST_CODE_STYLE_H
