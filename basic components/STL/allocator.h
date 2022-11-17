//
// Created by root on 11/17/22.
//

#ifndef CPPTEST_ALLOCATOR_H
#define CPPTEST_ALLOCATOR_H

#include <new>
#include <cstddef>
#include <cstdlib>
#include <climits>
#include <iostream>

namespace allocator {
    template<class T>
    inline T* allocate(ptrdiff_t size, T*) {
        std::set_new_handler(0);
        T *temp = (T*)(::operator new((size_t)(size * sizeof(T))));
    }
}

#endif //CPPTEST_ALLOCATOR_H
