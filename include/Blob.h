//
// Created by lixia on 2025/10/2.
//

#ifndef BLOB_H
#define BLOB_H
#include <vector>
#include <memory>

template <typename T> class BlobPtr;
template <typename T> class Blob;
template <typename T> bool operator==(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob &, const Blob &);

public:
    typedef T value_type;
    typedef std::vector<T>::size_type size_type;

    Blob();
    Blob(std::initializer_list<T> il);
    template <typename Iter> Blob(Iter beg, Iter end);
    Blob(T *, std::size_t);

    BlobPtr<T> begin() {
        return BlobPtr<T>(*this);
    }
    BlobPtr<T> end() {
        auto ret = BlobPtr<T>(*this, data->size());
        return ret;
    }
    size_type size() const {
        return data->size();
    }
    [[nodiscard]]
    bool empty() const {
        return data->empty();
    }
    void push_back(const T &t) {
        data->push_back(t);
    }
    void push_back(T &&t) {
        data->push_back(std::move(t));
    }
    void pop_back();

    T& front();
    T& back();
    T& at(size_type);
    const T& front() const;
    const T& back() const;
    const T& at(size_type) const;
    T& operator[](size_type i);
    const T& operator[](size_type i) const;

    void swap(Blob &b) noexcept {
        data.swap(b.data);
    }
private:
    std::shared_ptr<std::vector<T>> data;

    void check(size_type i, const std::string &msg) const;
};

template<typename T>
void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= size())
        throw std::out_of_range(msg);
}

template<typename T>
Blob<T>::Blob()
    : data(std::make_shared<std::vector<T>>()) {

}

template<typename T>
Blob<T>::Blob(std::initializer_list<T> il)
    : data(std::make_shared<std::vector<T>>(il)){

}

template<typename T>
template<typename Iter>
Blob<T>::Blob(Iter beg, Iter end)
    : data(std::make_shared<std::vector<T>>(beg, end)){

}

template<typename T>
Blob<T>::Blob(T *p, std::size_t n)
    :data(std::make_shared<std::vector<T>>(p, p + n)){

}

template<typename T>
void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template<typename T>
T &Blob<T>::front() {
    check(0, "front on empty Blob");
    return data->front();
}

template<typename T>
T &Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template<typename T>
T &Blob<T>::at(size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
const T &Blob<T>::front() const {
    check(0, "front on empty Blob");
    return data->front();
}

 template<typename T>
 const T &Blob<T>::back() const {
     check(0, "back on empty Blob");
     return data->back();
 }

template<typename T>
const T &Blob<T>::at(size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
T &Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
const T &Blob<T>::operator[](size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const Blob<T> &b) {
    os << "<";
    for (auto i = 0; i < b.size(); ++i){
        if (i != 0)
            os << ", ";
        os << b[i];
    }
    os << ">";
    return os;
}

template<typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs) {
    return *lhs.data == *rhs.data;
}

template<typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs) {
    return !(lhs == rhs);
}


/*
 * =============================== BlobPtr ==================================
 */
template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);


template <typename T>
class BlobPtr {
    friend bool operator==<T>(const BlobPtr&, const BlobPtr&);

public:
    BlobPtr() : curr(0) {}
    explicit BlobPtr(Blob<T> &a, const size_t sz = 0)
        : wptr(a.data), curr(sz) {}

    T& operator[](std::size_t i) {
        auto p = check(i, "subscript out of range");
        return (*p)[i];
    }
    const T& operator[](std::size_t i) const {
        auto p = check(i, "subscript out of range");
        return (*p)[i];
    }
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    T* operator->() const {
        return & this->operator*();
    }

    BlobPtr& operator++(); // 前缀++
    BlobPtr& operator--();
    BlobPtr operator++(int); // 后缀++
    BlobPtr operator--(int);
private:
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr = 0; // 数组中的当前位置

    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
};

template<typename T>
std::shared_ptr<std::vector<T> > BlobPtr<T>::check(std::size_t i, const std::string &msg) const {
    if (wptr.expired())
        throw std::runtime_error("unbound BlobPtr");
    auto ret = wptr.lock();
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template<typename T>
BlobPtr<T> &BlobPtr<T>::operator--() {
    --curr;
    check(-1, "decrement past begin of BlobPtr");
    return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    --*this;
    return ret;
}


template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>&  rhs) {
    auto l_data = lhs.check(lhs.curr);
    auto r_data = rhs.check(rhs.curr);
    return *l_data == *r_data;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>&  rhs) {
    return !(lhs == rhs);
}

template <typename T>
std::ostream & operator<<(std::ostream &os, const BlobPtr<T> &bp) {
    auto b = bp.check(bp.curr);
    os << "<" << *b << ">, curr = " << bp.curr;
    return os;
}
#endif //BLOB_H