//
// Created by lixia on 2025/8/15.
//

#include <iostream>
#include "../include/Sales_item.h"

int main(int argc, char *argv[]) {
    Sales_item item1, item2;
    std::cin >> item1 >> item2;
    // 首先检查item1和item2是否表示相同的书
    if (item1.isbn() == item2.isbn()) {
        std::cout << item1 + item2 << std::endl;
        return 0;
    } else {
        std::cerr << "Data must refer to same ISBN" << std::endl;
        return -1;
    }
}
