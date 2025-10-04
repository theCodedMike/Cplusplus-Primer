//
// Created by lixia on 2025/10/4.
//
#include <iostream>
using namespace std;

template <typename T>
double sum(const T &t1, const T &t2) {
    return t1 + t2;
}

int main(int argc, char *argv[]) {
    cout << sum(1, 2) << endl;
    cout << sum(3.4, 5.6) << endl;
}
