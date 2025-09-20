//
// Created by lixia on 2025/9/20.
//

#ifndef STRVEC_H
#define STRVEC_H
#include <memory>

class StrVec {
public:
    StrVec() = default;
    StrVec(const StrVec &); // 拷贝构造函数
    StrVec &operator=(const StrVec &); // 拷贝赋值运算符
    StrVec(const std::initializer_list<std::string> &);
    ~StrVec(); // 析构函数

    void push_back(const std::string &);
    void pop_back();
    void reserve(size_t new_cap);
    void resize(size_t new_size, const std::string &val = "");
    [[nodiscard]]
    bool empty() const {
        return first_free == elements;
    }
    [[nodiscard]]
    size_t size() const {
        return first_free - elements;
    }
    [[nodiscard]]
    size_t capacity() const {
        return cap - elements;
    }
    [[nodiscard]]
    std::string *begin() const {
        return elements;
    }
    [[nodiscard]]
    std::string *end() const {
        return first_free;
    }
    [[nodiscard]]
    std::string &front() const {
        return *elements;
    }
    [[nodiscard]]
    std::string &back() const {
        return *(first_free - 1);
    }
private:
    inline static size_t default_cap = 4;
    inline static std::allocator<std::string> alloc; // 分配元素

    std::string *elements = nullptr; // 指向数组首元素的指针
    std::string *first_free = nullptr; // 指向数组第一个空闲元素的指针
    std::string *cap = nullptr; // 指向数组尾后位置的指针

    void check_n_alloc() {
        if (size() == capacity()) {
            reallocate(size() == 0 ? default_cap : size() * 2);
        }
    }
    void free() const; // 销毁元素并释放内存
    void reallocate(size_t new_cap); // 获取更多内存并拷贝已有元素

    static std::pair<std::string *, std::string *> alloc_n_copy(const std::string *, const std::string *); // 拷贝给定范围内的元素
};

/****************************************************public****************************************************/
inline StrVec::StrVec(const StrVec & sv) {
    std::tie(elements, cap) = alloc_n_copy(sv.begin(), sv.end());
    first_free = cap;
}

inline StrVec &StrVec::operator=(const StrVec & rhs) {
    auto[fst, snd] = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = fst;
    first_free = snd;
    cap = snd;
    return *this;
}

inline StrVec::StrVec(const std::initializer_list<std::string> &il) {
    std::tie(elements, cap) = alloc_n_copy(il.begin(), il.end());
    first_free = cap;
}


inline StrVec::~StrVec() {
    free();
}

inline void StrVec::push_back(const std::string &s) {
    check_n_alloc();
    std::allocator_traits<std::allocator<std::string>>::construct(alloc, first_free++, s);
}

inline void StrVec::pop_back() {
    if (empty())
        return;
    std::allocator_traits<std::allocator<std::string>>::destroy(alloc, --first_free);
}

inline void StrVec::reserve(const size_t new_cap) {
    if (new_cap <= capacity())
        return;

    reallocate(new_cap);
}
inline void StrVec::resize(const size_t new_size, const std::string &val) {
    if (const size_t sz = size(); new_size < sz) {
        for (auto i = new_size; i < sz; ++i)
            pop_back();

    } else if (new_size > sz) {
        for (auto i = sz; i < new_size; ++i)
            push_back(val);
    }
}

/****************************************************private****************************************************/
/// first: 首地址
/// second: 尾后地址
inline std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *beg, const std::string *end) {
    // 分配空间以保存给定区间中的元素
    auto data = alloc.allocate(end - beg);

    return std::make_pair(data, std::uninitialized_copy(beg, end, data));
}

inline void StrVec::free() const {
    if (elements != nullptr) {
        // 逆序销毁旧元素
        for (auto iter = first_free; iter != elements;)
            std::allocator_traits<std::allocator<std::string>>::destroy(alloc, --iter);

        alloc.deallocate(elements, cap - elements);
    }
}

inline void StrVec::reallocate(const size_t new_cap) {
    const auto new_data = alloc.allocate(new_cap);
    // 把数据从旧内存移动到新内存
    auto dest = new_data;
    auto elem = elements;
    for (size_t i = 0, sz = size(); i < sz; ++i, ++elem, ++dest)
        std::allocator_traits<std::allocator<std::string>>::construct(alloc, dest, std::move(*elem));
    free();
    // 更新
    elements = new_data;
    first_free = dest;
    cap = new_data + new_cap;
}
#endif //STRVEC_H