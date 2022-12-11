//
// Created by root on 11/9/22.
//


#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include "practice sample/class_function.h"

std::mutex mtx;
std::condition_variable cond;
bool ready = false;

int dir[][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}  };

void do_print_id(int id) {
    std::unique_lock<std::mutex>lck(mtx);
    while (!ready) {
        cond.wait(lck);
    }
    std::cout<<"thread: "<<id<<std::endl;
}

void go() {
    std::unique_lock<std::mutex>lck(mtx);
    ready = true;
    cond.notify_all();
}

void smartPointer() {
    std::shared_ptr<int> a(new int(10));
    std::cout<<a.get()<<std::endl;

}

union xxx {
    int a;
    double b;
} t;

int main() {
    test();
//    std::cout << t.a << std::endl;
//    smartPointer();
//    const int &a = 10;
//
//    std::thread thread[10];
//    for (int i = 0; i < 10; i++) {
//        thread[i] = std::thread(do_print_id, i);
//    }
//    for (auto &th:thread) {
//        th.join();
//    }
//
//    go();
}

