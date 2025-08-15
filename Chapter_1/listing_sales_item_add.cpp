//
// Created by lixia on 2025/8/14.
//

#include <iostream>

#include "../include/Sales_item.h"

int main(int argc, char *argv[]) {
    Sales_item item1, item2;
    std::cin >> item1 >> item2; // 读取一对
    std::cout << item1 + item2 << std::endl;

    //
    // 0-201-78345-X 3 20.0
    // 0-201-78345-X 2 25
    //
    // 0-201-78345-X 5 110 22

    return 0;
}
