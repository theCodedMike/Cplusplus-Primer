//
// Created by lixia on 2025/8/14.
//

#include <iostream>
#include "../include/Sales_item.h"

int main(int argc, char *argv[]) {
    Sales_item book;
    std::cout << "Please Enter books sale data: " << std::endl;
    while (std::cin >> book)
        std::cout << "Book Info: " << book << "\n\n";

    return 0;
}
