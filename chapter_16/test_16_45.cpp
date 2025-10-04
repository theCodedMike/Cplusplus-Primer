//
// Created by lixia on 2025/10/4.
//
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void g(T&& val) {
    vector<T> v;
    v.push_back(val);
    cout << v.size() << ", v[0] = " << v[0] << endl;
}
int main(int argc, char *argv[]) {
    g(42);
}
