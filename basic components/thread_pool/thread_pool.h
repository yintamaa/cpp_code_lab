//
// Created by root on 11/25/22.
//

#ifndef CPPTEST_THREAD_POOL_H
#define CPPTEST_THREAD_POOL_H

#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>
#include <thread>

namespace ThreadPool {
struct data {
    std::mutex mutex;
    std::condition_variable cond;
    bool is_shutdown = false;
    std::queue<int> task_queue;
};

class ThreadPool {
private:
    std::thread *th;
    int size_;
    std::shared_ptr<data> data_;
public:1
    ~ThreadPool() = default;
    ThreadPool(ThreadPool &&) = default;
    ThreadPool() = default;
    explicit ThreadPool(int size) {
        data_ = std::make_shared<data>();
    }
    void excute();
};

}

#endif //CPPTEST_THREAD_POOL_H
