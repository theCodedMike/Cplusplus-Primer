//
// Created by lixia on 2025/8/16.
//

#include <iostream>

int main(int argc, char *argv[]) {
    int height = 175;
    int *pHeight = &height;
    std::cout << pHeight << " " << *pHeight << " " << height << std::endl; // 0x410edffc74 175 175
    pHeight++;
    *pHeight = 180;
    std::cout << pHeight << " " << *pHeight << " " << height << std::endl; // 0x41000000b4              这行代码有问题
}
