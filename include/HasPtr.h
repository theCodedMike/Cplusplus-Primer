//
// Created by lixia on 2025/9/18.
//

#ifndef HASPTR_H
#define HASPTR_H

#include <string>

// 行为像值的类
class HasPtrVal {
    std::string *ps;
    int i;

public:
    explicit HasPtrVal(const std::string &s = std::string())
        : ps(new std::string(s)), i(0) {}
    HasPtrVal(const HasPtrVal &hp);
    HasPtrVal& operator=(const HasPtrVal &hp);
    ~HasPtrVal() {delete ps;}
};

inline HasPtrVal::HasPtrVal(const HasPtrVal &hp) :
    ps(new std::string(*hp.ps)),
    i(hp.i)
{ }

inline HasPtrVal& HasPtrVal::operator=(const HasPtrVal &hp) {
    const auto new_ps = new std::string(*hp.ps); // 先创建出临时新的内存
    delete ps; // 再释放旧内存
    ps = new_ps;
    i = hp.i;
    return *this;
}

// 行为像指针的类
class HasPtrPtr {
    std::string *ps;
    int i;
    std::size_t *use; // 记录有多少个对象共享*ps的成员

public:
    explicit HasPtrPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
    HasPtrPtr(const HasPtrPtr &hp) :
        ps(hp.ps), i(hp.i), use(hp.use) { ++*use;}
    HasPtrPtr & operator=(const HasPtrPtr &hp);
    ~HasPtrPtr();
};

inline HasPtrPtr &HasPtrPtr::operator=(const HasPtrPtr &hp) {
    ++*hp.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = hp.ps;
    i = hp.i;
    use = hp.use;

    return *this;
}

inline HasPtrPtr::~HasPtrPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;
    }
}


#endif //HASPTR_H