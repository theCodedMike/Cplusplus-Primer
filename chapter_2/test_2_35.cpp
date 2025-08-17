//
// Created by lixia on 2025/8/17.
//

#include <iostream>

int f() {
    std::cout << "this is f function..." << std::endl;
    return 0;
}
int main(int argc, char *argv[]) {
    const int i = 42;
    auto j = i; // j is an int
    const auto &k = i; // k is a reference to const int
    auto *p = &i; // p is a pointer to const int
    const auto j2 = i, &k2 = i; // j2 is an int, k2 is a reference to const int

    // decltype
    decltype(f()) sum = i; // sum的类型就是函数f的返回值类型
    const int ki = 0, &kj = ki;
    decltype(ki) x = 0; // x的类型是const int
    decltype(kj) y = x; // y的类型是const int&
    //decltype(kj) z; // ❌ z是一个引用，必须初始化
}
