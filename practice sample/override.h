//
// Created by root on 12/9/22.
//

#ifndef CPPTEST_OVERRIDE_H
#define CPPTEST_OVERRIDE_H

class overRideFather {

public:
    overRideFather(overRideFather&& other) : val_(other.val_){}
    overRideFather(const overRideFather&) = delete;
    overRideFather& operator= (const overRideFather&) = delete;
    virtual void FatherFirst(int val) = 0;

private:
    int val_;
};

class overRideSon : public overRideFather {

public:
    void FatherFirst(int val) override;

private:

};

#endif //CPPTEST_OVERRIDE_H
