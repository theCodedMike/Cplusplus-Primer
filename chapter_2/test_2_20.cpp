//
// Created by lixia on 2025/8/16.
//

#include <iostream>

int main(int argc, char *argv[]) {
    int i = 5;
    int *p1 = &i;
    if (p1) {
        std::cout << "p1 is not nullptr" << std::endl; // 会输出
    }
    if (*p1) {
        std::cout << "*p1 is " << *p1 << std::endl; // *p1 is 5
    }
    *p1 = *p1 * *p1;
    std::cout << *p1 << " " << i << std::endl; // 25 25

    p1 = nullptr;
    if (!p1) {
        std::cout << "p1 is nullptr now!" << std::endl;
    }
}
