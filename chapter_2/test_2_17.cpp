//
// Created by lixia on 2025/8/16.
//

#include <iostream>

int main(int argc, char *argv[]) {
    int i, &ri = i;
    i = 5; ri = 10;
    std::cout << i << " " << ri << std::endl; // 10 10
}
