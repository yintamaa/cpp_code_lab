//
// Created by yintama on 2022/12/29.
//

#ifndef CPPTEST_PRACTICE_SAMPLE_STATIC_H_
#define CPPTEST_PRACTICE_SAMPLE_STATIC_H_

#include <iostream>

class StaticClass {

private:
	static int count_;
public:
	StaticClass(int x) {
		count_ = x;
	}
	static void print() {
		std::cout << count_ << std::endl;
	}
};

int StaticClass::count_ = 0;

#endif //CPPTEST_PRACTICE_SAMPLE_STATIC_H_
