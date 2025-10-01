//
// Created by lixia on 2025/9/30.
//
#include <iostream>
#include "../include/Sales_data.h"

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2) {
    if (std::less<T>()(v1, v2))
        return -1;
    if (std::greater<T>()(v1, v2))
        return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    const Sales_data sd1("ISBN-911", 10, 9.99);
    const Sales_data sd2("ISBN-912", 10, 9.99);

    cout << compare(sd1, sd2) << endl; // -1
}
