//
// Created by lixia on 2025/10/3.
//

#include <iostream>
using namespace std;

template <class T>
int compare(const T &, const T &);

int main(int argc, char *argv[]) {
    //compare("hi", "world"); // ❌
    compare("bye", "dad"); // ✔ ???
}

template <class T>
int compare(const T &v1, const T &v2) {
    return 0;
}