//
// Created by root on 11/9/22.
//

#ifndef CPPTEST_RWMUTEX_H
#define CPPTEST_RWMUTEX_H

#include <mutex>
#include <condition_variable>

// 用mutex实现rwmutex
class RWMutex {
private:
    int readCount;
    int writeCount;
    std::mutex readMutex;
    std::mutex writeMutex;
    std::condition_variable writeCondition;
    std::condition_variable readCondition;
public:
    RWMutex():readCount(0){}
    void RLock() {
        writeMutex.lock();
        readCount++;
        writeMutex.unlock();
    }
    void RUnlock() {
        writeMutex.lock();
        if (--readCount == 0) {
            readCondition.notify_one();
        }
        writeMutex.unlock();
    }
    void WLock() {
        writeMutex.lock();
        std::unique_lock<std::mutex>lock(writeMutex);
        while(readCount) {
            writeCondition.wait(lock);
        }
        writeMutex.unlock();
    }
    void WUnlock() {
        writeMutex.unlock();
    }
};


#endif //CPPTEST_RWMUTEX_H
