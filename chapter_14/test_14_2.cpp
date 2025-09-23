//
// Created by lixia on 2025/9/23.
//
#include <iostream>
#include "../include/Sales_data.h"

using namespace std;


int main(int argc, char *argv[]) {
    Sales_data sd1;
    cout << "Enter book number, units sold and price: " << endl;
    cin >> sd1;

    Sales_data sd2;
    cout << "Enter book number, units sold and price: " << endl;
    cin >> sd2;

    const auto sd3 = sd1 + sd2;
    cout << sd3 << endl;
    sd1 += sd2;
    cout << sd1 << endl;
}
