//
// Created by lixia on 2025/8/27.
//

#include "../include/Chapter6.h"

int main(int argc, char *argv[]) {
    for (int i = 1; i <= 10; ++i)
        cout << test_ret() << " ";
}

int test_ret() {
    static int cnt = -1;
    return ++cnt;
}