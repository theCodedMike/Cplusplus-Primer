//
// Created by lixia on 2025/9/25.
//
#include <iostream>
#include <string>
#include "../include/Sales_data.h"

using namespace std;


int main(int argc, char *argv[]) {
    const Sales_data sd("ISBN-911", 10, 15.5);
    cout << static_cast<string>(sd) << endl; // ISBN-911
    cout << static_cast<double>(sd) << endl; // 155
    if (sd) { // 这里可以不用static_cast<bool>
        cout << sd << endl;
    }

    if (const Sales_data sd2; sd2)
        cout << sd2 << endl;
    else
        cout << "sd2 is empty" << endl; // output
}
