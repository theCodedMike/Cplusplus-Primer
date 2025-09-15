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

    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;

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
    void pop_back() const;
    [[nodiscard]] std::string & front() const;
    [[nodiscard]] std::string & back() const;
    [[nodiscard]] StrBlobPtr begin() const;
    [[nodiscard]] StrBlobPtr end() const;
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

/////////////////////////////// StrBlobPtr /////////////////////////////////
class StrBlobPtr {
    [[nodiscard]]
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr; // 在数组中的当前位置

public:
    StrBlobPtr() : curr(0) {}
    explicit StrBlobPtr(const StrBlob &sb, const size_t sz = 0) : wptr(sb.data), curr(sz) {}
    [[nodiscard]] std::string & deref() const;
    StrBlobPtr & incr();
};

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
    auto p = check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}


inline StrBlobPtr StrBlob::begin() const {
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const {
    return StrBlobPtr(*this, data->size());
}


#endif //STRBLOB_H