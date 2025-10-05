//
// Created by lixia on 2025/10/5.
//
#include <iostream>
using namespace std;


template <typename T>
ostream & print(ostream &, const T &);

template <typename T, typename... Args>
ostream & print(ostream &os, const T &t, const Args&... rest) {
    os << t << ", ";
    return print(os, rest...);
}

template <typename T>
ostream & print(ostream & os, const T &t) {
    return os << t;
}


int main(int argc, char *argv[]) {
    print(cout, 1);
    cout << endl; // 1
    print(cout, 1, 2.5);
    cout << endl; // 1, 2.5
    print(cout, 1, 2.5, "hello");
    cout << endl; // 1, 2.5, hello
    print(cout, 1, 2.5, "hello", true);
    cout << endl; // 1, 2.5, hello, 1
    print(cout, 1, 2.5, "hello", true, 'A'); // 1, 2.5, hello, 1, A
}
