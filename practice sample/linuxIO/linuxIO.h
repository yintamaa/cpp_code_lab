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
    int SetNonblocking(int fd); // 设置非阻塞
    void receive();
public:
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

// 设置w
int linuxIO::SetNonblocking(int fd) {
    // fcntl(fd, F_GETFL) 获取旧的文件描述符标志
    return fcntl(fd, F_SETFL, fcntl(fd, F_GETFL)|O_NONBLOCK);
}

// 返回监听套接字
int buildSocket(char* ip, int port) {
    int serverLen, clientLen;
    sockaddr_in serverAddr;
    sockaddr_in clientAddr;

    serverAddr.sin_family = AF_INET; // TCP/IP IPV4
    inet_pton(AF_INET, ip, &serverAddr.sin_addr);
    serverAddr.sin_port = htons(port);
    int listenFD = socket(AF_INET, SOCK_STREAM, 0); // 流式套接字,IPV4,TCP
    assert(listenFD > 0);
    int ret = bind(listenFD, (struct sockaddr*)&serverAddr, sizeof serverAddr);
    assert(ret == 0);
    return listenFD;
}

void linuxIO::Select() {
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    int result;
    fd_set readfds, testfds;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET; // TCP/IP IPV4
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(9734);
    server_len = sizeof(server_address);
//    while(1) {
//        int keyboard = open("/dev/tty",O_RDONLY | O_NONBLOCK);
//        assert(keyboard>0);
//        fd_set readFD;
//        FD_ZERO(&readFD);
//        FD_SET(keyboard, &readFD);
//        int ret = select(keyboard+1, &readFD, nullptr,nullptr, nullptr);
//        if (ret == -1) printf("select error\n");
//        else if(ret == 0) {
//            printf("timeout\n");
//        } else {
//            if(FD_ISSET(keyboard, &readFD)) {
//                char data;
//                int ret = read(keyboard, &data, 1);
//            }
//        }
//    }
    return ;
}

#endif //CPPTEST_LINUXIO_H
