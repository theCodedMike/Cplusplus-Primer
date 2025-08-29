//
// Created by lixia on 2025/8/29.
//
#include <iostream>
#include <vector>

using namespace std;
int add(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int divi(int a, int b);

using arith_ops = int (*)(int, int);

int main(int argc, char *argv[]) {
    const vector<arith_ops> funcs = {add, sub, mult, divi};
    for (const auto func : funcs) {
        cout << func(10, 5) << endl;
    }
}

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mult(int a, int b) {
    return a * b;
}

int divi(int a, int b) {
    if (b == 0) {
        cout << "b cannot be zero." << endl;
        return 0;
    }

    return a / b;
}