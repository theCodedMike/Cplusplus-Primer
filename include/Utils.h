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

#endif //UTILS_H