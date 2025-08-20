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
    auto it = container.begin();
    auto end = container.end();

    while (it != end) {
        std::cout << *it;
        ++it;
        if (it != end) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

#endif //UTILS_H