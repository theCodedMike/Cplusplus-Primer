//
// Created by lixia on 2025/8/15.
//

#include <iostream>

int main(int argc, char *argv[]) {
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i)
        sum += i;

    std::cout << i << " " << sum << std::endl; // 100 45
}
