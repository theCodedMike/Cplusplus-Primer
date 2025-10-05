//
// Created by lixia on 2025/10/5.
//
#include <iostream>
#include <unordered_set>

#include "../include/Sales_data.h"

using namespace std;


int main(int argc, char *argv[]) {
    unordered_multiset<Sales_data> bookstore;
    bookstore.emplace("ISBN-911", 1, 10);
    bookstore.emplace("ISBN-911", 1, 10);
    bookstore.emplace("ISBN-911", 1, 10);
    bookstore.emplace("ISBN-912", 2, 20);
    bookstore.emplace("ISBN-912", 2, 20);
    bookstore.emplace("ISBN-913", 3, 15);
    bookstore.emplace("ISBN-913", 3, 15);

    for (const auto & data: bookstore) {
        cout << data << endl;
    }
}
