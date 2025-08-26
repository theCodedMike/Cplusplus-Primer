//
// Created by lixia on 2025/8/26.
//

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int divisor, dividend;
    cout << "Enter two integers: ";
    cin >> divisor >> dividend;

    if (dividend == 0)
        throw runtime_error("Dividend cannot be zero.");

    cout << divisor << " / " << dividend << " = " << (divisor / dividend) << endl;
}
