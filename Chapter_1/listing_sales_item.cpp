//
// Created by lixia on 2025/8/14.
//

#include <iostream>
#include "../include/Sales_item.h"

int main(int argc, char *argv[]) {
    Sales_item book;
    // 读入ISBN号、售出的册数以及销售价格
    std::cin >> book;
    // 写入ISBN号、售出的册数、总销售额和平均价格
    std::cout << book << std::endl;

    //
    // 0-201-70353-X 4 24.99
    //
    // 0-201-70353-X 4 99.96 24.99
    return 0;
}
