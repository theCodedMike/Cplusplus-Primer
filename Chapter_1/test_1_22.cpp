//
// Created by lixia on 2025/8/15.
//

#include <iostream>
#include "../include/Sales_item.h"

int main(int argc, char *argv[]) {
    Sales_item total, book;

    std::cout << "Enter books sale data:\n";
    while (std::cin >> book) {
        total += book;
    }

    std::cout << "Total:" << std::endl;
    std::cout << total << std::endl;

    // 7-S-55321 2 34
    // 7-S-55321 10 7.2
    // 7-S-55321 7 10
    //
    // Total:
    // 7-S-55321 19 210 11.0526
    return 0;
}
