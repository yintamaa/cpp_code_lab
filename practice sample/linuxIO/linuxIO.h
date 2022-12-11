//
// Created by root on 11/23/22.
//

#ifndef CPPTEST_LINUXIO_H
#define CPPTEST_LINUXIO_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>
#include <errno.h>
#include <stdbool.h>
#include <assert.h>

class linuxIO {
private:
    int listen_fd; // 监听fd
    int epoll_set_fd; // epoll集合句柄
    epoll_event *events; // epoll事件数组
    void epoll_add_fd(int epoll_fd, int fd, bool is_et); // 添加文件描述符到集合
    void epoll_ET_handler(struct epoll_event* events, int number, int epoll_fd, int listen_fd); // ET处理
    void epoll_LT_handler(); // LT处理

    void receive();
public:
    int SetNonblocking(int fd); // 设置非阻塞
    linuxIO(int epoll_size, int event_size) {
        epoll_set_fd = epoll_create(epoll_size);
        events = new epoll_event[epoll_size];
    }
    ~linuxIO() {
        delete []events;
    }
    void Select();
    void poll();
    void epoll(bool is_et);
};





#endif //CPPTEST_LINUXIO_H
