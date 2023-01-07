//
// Created by Administrator on 2023/1/8.
//

#ifndef CPPTEST_PRIORITY_QUEUE_H
#define CPPTEST_PRIORITY_QUEUE_H

#include <iostream>

enum ErrCode{
    kSUCCESS = 0,
    kPOP_ERROR = -1,
    kTOP_ERROR = -2,
};

class PriorityQueue {
public:
    PriorityQueue(size_t size) {
        size_ = size;
        heap_ = new int[size_];
        max_id_ = 0;
    }
    void push(int val) {
        if (max_id_ < size_) {
            heap_[max_id_] = val;
            PushUp(max_id_);
            max_id_++;
        }
    }
    int top(int &val) {
        if (max_id_ < 0) {
            return kTOP_ERROR;
        }
        val = heap_[0];
        std::cout << val << std::endl;
        return kSUCCESS;
    }
    int pop() {
        if (max_id_ < 0) {
            return kPOP_ERROR;
        }
        heap_[0] = heap_[--max_id_];
        PushDown(0);
    }
private:
    int *heap_, max_id_, size_;
    void PushUp(int id) {
//        std::cout << "id: " << id << std::endl;
        while (id > 0) {
            if (heap_[id] < heap_[id / 2]) {
                std::swap(heap_[id], heap_[id / 2]);
                id = id / 2;
            } else {
                return ;
            }
        }
    }
    void PushDown(int id) {
        while (id < max_id_) {
            if ((id << 1) < max_id_ && heap_[id << 1] < heap_[id] && heap_[id << 1] < heap_[id << 1 | 1]) {
                std::swap(heap_[id << 1], heap_[id]);
                id = id << 1;
            } else if ((id << 1 | 1) < max_id_ && heap_[id << 1 | 1] < heap_[id] && heap_[id << 1 | 1] < heap_[id << 1]){
                std::swap(heap_[id << 1 | 1], heap_[id]);
                id = id << 1 | 1;
            } else {
                return ;
            }
        }
    }
};

void TestPriorityQueue() {
    int val;
    PriorityQueue pq(1000);
    for (int i = 100; i > 0; i--) {
        pq.push(i);
        pq.top(val);
        if (val != i) {
            std::cout << "push error" << std::endl;
        }
    }
    for (int i = 1; i <= 100; i++) {
        pq.pop();
        pq.top(val);
        if (val != i + 1) {
            std::cout << "pop error" << std::endl;
        }
    }
}

#endif //CPPTEST_PRIORITY_QUEUE_H
