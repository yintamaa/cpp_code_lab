//
// Created by Administrator on 2022/12/22.
//

#ifndef CPPTEST_HISTORY_MAP_H
#define CPPTEST_HISTORY_MAP_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <unordered_map>
#include <vector>

class HistoryMap {

struct node {
    int del_time;
    std::string value;
    node(std::string& value, int del_time = 0):del_time(del_time), value(value){}
    node(int del_time):del_time(del_time){}
    bool operator < (const node &temp_node) const {
        return del_time < temp_node.del_time;
    }
    node& operator = (const node& temp_node) {
        this -> del_time = temp_node.del_time;
        this -> value = temp_node.value;
        return *this;
    }
};

struct Status {
    int err_code;
    Status(int err_code):err_code(err_code){}
};

enum Code {
    kSuccess = 0,
    kNotFound = -24007,

};

typedef std::unordered_map<std::string, std::vector<node> > HisMap;

public:
    int Get(const std::string &key, std::string* value) {
        if (!his_map_.count(key)) {
            return kNotFound;
        } else {
            auto& vec = his_map_[key];
            if (vec.back().del_time == 0) { // 0還是指針nullptr好
                *value = vec.back().value;
                return kSuccess;
            } else {
                return kNotFound;
            }
        }
    }
    int Get_By_Time(const std::string &key, std::string* value, const unsigned timestamp) {
        if (!his_map_.count(key)) {
            return kNotFound;
        } else {
            auto& vec = his_map_[key];
            auto it = std::lower_bound(vec.begin(), vec.end(), node(timestamp));
            if (it == vec.end()) {
                return kNotFound;
            } else {

            }
        }
    }
    void Put(const std::string &key, const std::string &value) {

    }
    void Del(const std::string &key) {

    }

private:
    HisMap his_map_;
};


#endif //CPPTEST_HISTORY_MAP_H
