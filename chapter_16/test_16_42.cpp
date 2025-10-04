//
// Created by lixia on 2025/10/4.
//

#include <iostream>
using namespace std;

template <typename T> void g1(T&& val) {
    cout << val << endl;
}

template <typename T> void g2(T val) {
    cout << val << endl;
}

template <typename T> void g3(const T &val) {
    cout << val << endl;
}

int main(int argc, char *argv[]) {
    int i = 2; const int ci = i;

    g1(i);
    g1(ci);
    g1(i * ci);
    g1(i = ci);
    cout << endl;

    g2(i);
    g2(ci);
    g2(i * ci);
    g2(i = ci);
    cout << endl;

    g3(i);
    g3(ci);
    g3(i * ci);
    g3(i = ci);
    cout << endl;
}
