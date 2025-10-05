//
// Created by lixia on 2025/8/20.
//

#ifndef UTILS_H
#define UTILS_H

#include <iostream>

// 通用的打印容器函数模板
template<typename Container>
void print_collection(const Container& container) {
    std::cout << "[";
    auto beg = std::begin(container);
    auto end = std::end(container);

    while (beg != end) {
        std::cout << *beg;
        ++beg;
        if (beg != end) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}


// 正确的实现方式应该是：
template<std::size_t I = 0, typename... Tuple>
std::enable_if_t<I == sizeof...(Tuple), void> print_tuple(const std::tuple<Tuple...>&) {
    std::cout << std::endl;
}

template<std::size_t I = 0, typename... Tuple>
std::enable_if_t<I < sizeof...(Tuple), void> print_tuple(const std::tuple<Tuple...>& t) {
    if constexpr (I == 0)
        std::cout << "[";

    std::cout << std::get<I>(t);
    if constexpr (I + 1 < sizeof...(Tuple))
        std::cout << ", ";
    else
        std::cout << "]";

    print_tuple<I + 1>(t);  // 递归调用时传递参数
}

template <typename Pair>
void print_pair(const Pair& pair) {
    std::cout << "[" << pair.first << ", " << pair.second << "]" << std::endl;
}
#endif //UTILS_H