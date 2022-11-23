//
// Created by root on 11/23/22.
//

#ifndef CPPTEST_LINUXIO_H
#define CPPTEST_LINUXIO_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

class linuxIO {
private:
    int listenFD;
public:
    void Select();
    void poll();
    void epoll();
};

void linuxIO::Select() {
    while(1) {
        int keyboard = open("/dev/tty",O_RDONLY | O_NONBLOCK);
        assert(keyboard>0);
        fd_set readFD;
        FD_ZERO(&readFD);
        FD_SET(keyboard, &readFD);
        int ret = select(keyboard+1, &readFD, nullptr,nullptr, nullptr);
        if (ret == -1) printf("select error\n");
        else if(ret == 0) {
            printf("timeout\n");
        } else {
            if(FD_ISSET(keyboard, &readFD)) {
                char data;
                int ret = read(keyboard, &data, 1);
            }
        }
    }
    return ;
}

void linuxIO::poll() {

}

#endif //CPPTEST_LINUXIO_H
