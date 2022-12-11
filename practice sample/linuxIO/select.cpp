//
// Created by root on 12/12/22.
//

#include "linuxIO.h"

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