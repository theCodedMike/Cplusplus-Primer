//
// Created by lixia on 2025/9/10.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include "../include/Sales_data.h"

using namespace std;


bool compare_isbn(const Sales_data &lhs, const Sales_data &rhs) {
    return lhs.isbn() < rhs.isbn();
}


int main(int argc, char *argv[]) {
    std::vector<Sales_data> data = {
        Sales_data("ISBN-912-1111", 4, 15),
        Sales_data("ISBN-912-1112", 9, 20),
        Sales_data("ISBN-911-4567", 3, 10),
        Sales_data("ISBN-913-9877", 23, 11),
        Sales_data("ISBN-911-4568", 10, 11),
        Sales_data("ISBN-912-1156", 15, 8),
    };

    auto cmp_isbn = [](const Sales_data &lhs, const Sales_data &rhs) {
        return lhs.isbn() < rhs.isbn();
    };
    ranges::sort(data, cmp_isbn);

    for (auto &sales_data: data) {
        print(cout, sales_data);
        cout << endl;
    }
}
