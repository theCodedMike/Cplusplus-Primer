//
// Created by lixia on 2025/8/15.
//

#include <iostream>
#include "../include/Sales_item.h"

int main(int argc, char *argv[]) {
    Sales_item currBook, nextBook;

    if (std::cin >> currBook) {
        int cnt = 1;
        while (std::cin >> nextBook) {
            if (currBook.isbn() == nextBook.isbn())
                cnt++;
            else {
                std::cout << currBook.isbn() << ": " << cnt << std::endl;
                currBook = nextBook;
                cnt = 1;
            }
        }

        std::cout << currBook.isbn() << ": " << cnt << std::endl;
    }
}
