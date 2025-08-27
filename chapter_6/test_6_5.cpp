//
// Created by lixia on 2025/8/27.
//

#include "../include/Chapter6.h"

int main(int argc, char *argv[]) {
    print_absolute_value(5, 5.5);
    print_absolute_value(-5, -5.5);
}

void print_absolute_value(int a, double b) {
    cout << a << ", it's absolute value is " << abs(a) << endl;
    cout << b << ", it's absolute value is " << abs(b) << endl;
}