//
// Created by lixia on 2025/8/17.
//

#include <iostream>

int main(int argc, char *argv[]) {
    int a = 3, b = 4;
    decltype(a) c = a; // int c = a;
    decltype((b)) d = a; // int &d = a;
    ++c;
    ++d;

    std::cout << a << " " << b << " " << c << " " << d << std::endl; // 4 4 4 4
}
