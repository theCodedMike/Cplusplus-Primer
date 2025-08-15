#include <iostream>
//
// Created by lixia on 2025/8/14.
//
int main(int argc, char *argv[]) {
    float sum = 0, val = 0;
    while (std::cin >> val)
        sum += val;

    std::cout << "sum is " << sum << std::endl;
}
