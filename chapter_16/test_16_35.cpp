//
// Created by lixia on 2025/10/3.
//

#include <iostream>
using namespace std;

template <typename T>
T calc(T t, int i) {
    if (i > 0)
        cout << "calc...";

    return t;
}

template <typename T>
T fcn(T t1, T t2) {
    if (t1 >= t2)
        return t1;
    return t2;
}

int main(int argc, char *argv[]) {
    double d; float f; char c = 'a';
    calc(c, 'c'); // ✔
    calc(d, f); // ✔
    fcn(c, 'c'); // ✔
    //fcn(d, f); // ❌
}
