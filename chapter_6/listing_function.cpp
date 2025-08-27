//
// Created by lixia on 2025/8/27.
//

#include "../include/Chapter6.h"

int main(int argc, char *argv[]) {
    // 函数基础
    int val = 5;
    cout << val << "! = " << fact(val) << endl;

    for (size_t i = 0; i != 10; ++i)
        cout << count_calls() << ' ';
    cout << endl;

}

int fact(int val) {
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

size_t count_calls() {
    static size_t ctr = 0; // 调用结束后，这个值仍然有效
    return ++ctr;
}