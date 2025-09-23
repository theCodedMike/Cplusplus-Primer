//
// Created by lixia on 2025/9/23.
//
#include <iostream>

#include "../include/Sales_data.h"

using namespace std;


int main(int argc, char *argv[]) {
    Sales_data sd1("ISBN-911", 30, 15);
    Sales_data sd2("ISBN-911", 30, 15);
    Sales_data sd3("ISBN-912", 30, 15);

    cout << (sd1 == sd2) << endl; // 1
    cout << (sd1 != sd3) << endl; // 1
}
