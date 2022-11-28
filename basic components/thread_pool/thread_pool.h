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

namespace ThreadPoolNames {

struct task {
    std::function<void(int)> func;
};

struct data {
    std::mutex mutex;
    std::condition_variable cond;
    bool is_shutdown = false;
    std::queue<task> task_queue;
};

class ThreadPool {
private:
    std::thread *th;
    int size_;
    std::shared_ptr<data> data_;
public:
    ~ThreadPool() = default;
    ThreadPool(ThreadPool &&) = default;
    ThreadPool() = default;
    explicit ThreadPool(int size);
    void excute(task t);
};
}

#endif //CPPTEST_THREAD_POOL_H
