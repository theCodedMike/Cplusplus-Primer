//
// Created by lixia on 2025/9/13.
//

#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <memory>
#include <string>

class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
    using size_type = std::vector<std::string>::size_type;

public:
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    std::shared_ptr<std::vector<std::string>> get_data() {
        return data;
    }
    [[nodiscard]] size_type size() const {
        return data->size();
    }
    [[nodiscard]] bool empty() const {
        return data->empty();
    }
    void push_back(const std::string &t) const {
        data->push_back(t);
    }
    void push_back(std::string &&t) const {
        data->push_back(std::move(t));
    }
    void pop_back() const;
    [[nodiscard]] std::string & front() const;
    [[nodiscard]] std::string & back() const;
    [[nodiscard]] StrBlobPtr begin() const;
    [[nodiscard]] StrBlobPtr end() const;

    bool operator==(const StrBlob &) const;
    bool operator!=(const StrBlob &) const;
    std::string & operator[](const std::size_t n) {
        return (*data)[n];
    }
    const std::string & operator[](const std::size_t n) const {
        return (*data)[n];
    }

private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

inline StrBlob::StrBlob()
    : data(std::make_shared<std::vector<std::string>>()) {}

inline StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

inline void StrBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

inline std::string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

inline std::string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back() const {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

inline bool StrBlob::operator==(const StrBlob &rhs) const {
    if (size() != rhs.size())
        return false;
    for (size_type i = 0, sz = size(); i < sz; ++i) {
        if (data->at(i) != rhs.data->at(i))
            return false;
    }

    return true;
}

inline bool StrBlob::operator!=(const StrBlob &rhs) const {
    return !(*this == rhs);
}

/////////////////////////////// StrBlobPtr /////////////////////////////////
class StrBlobPtr {
    friend std::ostream & operator<<(std::ostream &, const StrBlobPtr &);

public:
    StrBlobPtr() : curr(0) {}
    explicit StrBlobPtr(const StrBlob &sb, const size_t sz = 0) : wptr(sb.data), curr(sz) {}
    [[nodiscard]] std::string & deref() const;
    StrBlobPtr & incr();

    StrBlobPtr & operator++(); // 前置运算
    StrBlobPtr & operator--();
    StrBlobPtr operator++(int); // 后置运算
    StrBlobPtr operator--(int);
    std::string & operator*() const {
        const auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    std::string * operator->() const {
        return & this->operator*();
    }

private:
    [[nodiscard]]
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; // 在数组中的当前位置

};

inline std::ostream &operator<<(std::ostream & os, const StrBlobPtr & sbp) {
    os << sbp.deref();
    return os;
}


inline std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(const std::size_t i, const std::string &msg) const {
    if (wptr.expired())
        throw std::runtime_error("unbound StrBlobPtr");
    auto ret = wptr.lock();
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

inline std::string & StrBlobPtr::deref() const {
    const auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

inline StrBlobPtr & StrBlobPtr::incr() {
    auto _ = check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr StrBlob::begin() const {
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const {
    return StrBlobPtr(*this, data->size());
}

inline StrBlobPtr &StrBlobPtr::operator++() {
    auto _ = check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

inline StrBlobPtr &StrBlobPtr::operator--() {
    --curr;
    auto _ = check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

// 使用前置运算符时才需要检查
inline StrBlobPtr StrBlobPtr::operator++(int) {
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

inline StrBlobPtr StrBlobPtr::operator--(int) {
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

#endif //STRBLOB_H