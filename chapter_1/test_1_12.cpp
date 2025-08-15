//
// Created by lixia on 2025/8/14.
//

#include <iostream>

int main(int argc, char *argv[]) {
    int sum = 0;
    for (int i = -100; i <= 100; i++)
        sum += i;

    std::cout << "sum = " << sum << std::endl; // sum = 0
}
