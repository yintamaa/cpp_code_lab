//
// Created by yintama on 2022/12/27.
//

#ifndef CPP_CODE_LAB_PRACTICE_SAMPLE_SMART_POINTER_H_
#define CPP_CODE_LAB_PRACTICE_SAMPLE_SMART_POINTER_H_

#include <iostream>
#include <memory>

template <typename T>
class SmartPointerBuilder {
  // https://www.cnblogs.com/wxquare/p/4759020.html
private:
    T* ptr_;
    size_t* count_;
public:
    SmartPointerBuilder(T* ptr = nullptr):ptr_(ptr) {
        if (ptr_) {
            count_ = new size_t(1);
        } else {
            count_ = new size_t(0);
        }
    }
	SmartPointerBuilder(const SmartPointerBuilder& ptr) {
		if (this != ptr) {
			this -> ptr_ = ptr.ptr_;
			this -> count_ = ptr.count_;
			(*this -> count_)++;
		}
	}
	SmartPointerBuilder& operator = (const SmartPointerBuilder& ptr) {
		if (this -> ptr == ptr.ptr_) {
			return *this;
		} else {
			if (this -> ptr_) {
				(*this)->count_--;
				(*this->count_) --;
				if (*this -> count_ == 0) {
					delete this -> ptr_;
					delete this -> count_;
				}
			}
		}
		this -> ptr = ptr.ptr_;
		this -> count_ = ptr.count_;
		(*this -> count_)++;
		return *this;
	}
};

class SmartPointer {
public:
    SmartPointer() = default;
    SmartPointer(const SmartPointer&) = delete;
    SmartPointer(SmartPointer&&) = default;
    virtual ~SmartPointer() = default;
    void bind() {
      shared_ptr_ = std::make_shared<int>(10);
      weak_ptr_ = shared_ptr_;
      unique_ptr_ = std::unique_ptr<int>(new int(10));
    }
private:
    std::shared_ptr<int>shared_ptr_;
    std::weak_ptr<int>weak_ptr_;
    std::unique_ptr<int>unique_ptr_;
};

#endif // CPP_CODE_LAB_PRACTICE_SAMPLE_SMART_POINTER_H_
