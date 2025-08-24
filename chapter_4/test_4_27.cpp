//
// Created by lixia on 2025/8/24.
//

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    unsigned long u11 = 3, u12 = 7;
    cout << (u11 & u12) << endl;  // 3
    cout << (u11 && u12) << endl; // 1
    cout << (u11 | u12) << endl;  // 7
    cout << (u11 || u12) << endl; // 1
}
