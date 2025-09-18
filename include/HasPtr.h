//
// Created by lixia on 2025/9/18.
//

#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <iostream>


// 行为像值的类
class HasPtrVal {
    std::string *ps;
    int i;

public:
    explicit HasPtrVal(const std::string &s = std::string(), const int i = 0)
        : ps(new std::string(s)), i(i) {}
    HasPtrVal(const HasPtrVal &hp);
    HasPtrVal& operator=(const HasPtrVal &hp);
    //HasPtrVal &operator=(HasPtrVal rhs);
    ~HasPtrVal() {delete ps;}

    bool operator<(const HasPtrVal &rhs) const {
        if (*ps == *rhs.ps)
            return i < rhs.i;
        return *ps < *rhs.ps;
    }
    bool operator==(const HasPtrVal &rhs) const {
        return *ps == *rhs.ps && i == rhs.i;
    }
    void swap(HasPtrVal &rhs) noexcept;
//friend
    friend void swap(HasPtrVal &lhs, HasPtrVal &rhs) noexcept;
    friend std::ostream & operator<<(std::ostream &os, const HasPtrVal &hp);
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
/*
inline HasPtrVal& HasPtrVal::operator=(HasPtrVal rhs) {
    swap(*this, rhs);
    return *this;
}
*/

inline void HasPtrVal::swap(HasPtrVal &rhs) noexcept {
    using std::swap;
    swap(ps, rhs.ps);
    swap(i, rhs.i);
    std::cout << "...HasPtrVal::swap..." << std::endl;
}

inline void swap(HasPtrVal &lhs, HasPtrVal &rhs) noexcept{
    using std::swap;
    swap(lhs.ps, rhs.ps); // 交换指针而不是交换string数据
    swap(lhs.i, rhs.i);
    std::cout << "...swap..." << std::endl;
    //std::swap(lhs.ps, rhs.ps); // ❌ 这样写就使用了标准库版本的swap，而不是HasPtrVal的swap
}

inline std::ostream & operator<<(std::ostream &os, const HasPtrVal &hp) {
    os << "(" << *hp.ps << " " << hp.i << ")";
    return os;
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