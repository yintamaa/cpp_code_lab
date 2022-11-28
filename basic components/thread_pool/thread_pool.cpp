//
// Created by root on 11/28/22.
//

#include "thread_pool.h"

namespace ThreadPoolNames {
    void ThreadPool::excute(task t) {
        std::lock_guard<std::mutex>(data_->mutex);
        data_->task_queue.push(t);
        data_->cond.notify_one();
    }
    ThreadPool::ThreadPool(int size) {
        data_ = std::make_shared<data>();
        for(int i = 0; i < size; i++) {
            std::thread(
                    [data = data_] {
                        std::unique_lock<std::mutex>lk(data->mutex);
                        while(1) {
                            if(!data -> task_queue.empty()) {
                                auto current = std::move(data->task_queue.front());
                                data->task_queue.pop();
                                lk.unlock();
                                current.func(1);
                                lk.lock();
                            } else if (data->is_shutdown) {
                                break;
                            } else {
                                data->cond.wait(lk);
                            }
                        }
                    }
                    ).detach();
        }
    }
}