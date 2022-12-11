//
// Created by root on 11/24/22.
//

#include "linuxIO.h"

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

void linuxIO::epoll_add_fd(int epoll_fd, int fd, bool is_et) {
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN; // fd为可读
    if(is_et) {
        event.events |= EPOLLET; // 开启ET模式
    }
    // epoll句柄， 选项，需要监听的fd，需要监听的事情
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &event);
    SetNonblocking(fd); // 设置为非阻塞
}

void linuxIO::epoll(bool is_et) {
    int listenFD = buildSocket("127.0.0.1", 8080);
    int ret = listen(listenFD, 5); // 5是最大建立的连接数（已经完成三次握手的连接数）
    assert(ret == 0);
    epoll_event events[100];
    int epoll_set_fd = epoll_create(5); // epoll事件表大小
    assert(epoll_set_fd == 0);
    epoll_add_fd(epoll_set_fd, listenFD, is_et);
    while(1) {
        // timeout: -1代表永不超时，0代表立刻返回
        int event_nums = epoll_wait(epoll_set_fd, events, 1024, -1);
        assert(ret >= 0);
        if(is_et) {
            epoll_ET_handler(events, event_nums, epoll_set_fd, listenFD);
        } else {
            epoll_LT_handler();
        }
    }
    close(listenFD);
}

void linuxIO::epoll_LT_handler() {

}

void linuxIO::epoll_ET_handler(struct epoll_event* events, int event_nums, int epoll_fd, int listen_fd) {
    for(int i = 0; i < event_nums; ++i) {
        int sockFD = events[i].data.fd;
        if(sockFD == listen_fd) { // 监听感知到新的连接
            sockaddr_in client_address;
            socklen_t client_addr_length = sizeof(client_address);
            int connfd = accept(listen_fd, (struct sockaddr*)&client_address, &client_addr_length);
            while(connfd > 0) { // 获取连接请求队列的第一个连接请求
                printf("链接建立，Client : %s\n",inet_ntoa(client_address.sin_addr));
                epoll_add_fd(epoll_set_fd, connfd, true);
            }
        } else if (events[i].events & EPOLLIN) { // 有数据写入

        } else {
            printf("something error\n");
        }
    }
}

void linuxIO::receive() {

}

// 设置w
int linuxIO::SetNonblocking(int fd) {
    // fcntl(fd, F_GETFL) 获取旧的文件描述符标志
    return fcntl(fd, F_SETFL, fcntl(fd, F_GETFL)|O_NONBLOCK);
}
