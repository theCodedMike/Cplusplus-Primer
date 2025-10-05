//
// Created by lixia on 2025/10/5.
//

#include <cstring>
#include <iostream>
#include <vector>

using namespace std;


template <typename T>
size_t count(const vector<T> &vec, const T &val) {
    auto res = 0;
    for (const auto & v: vec) {
        if (v == val)
            ++res;
    }
    return res;
}

template <>
size_t count(const vector<const char*> &vec, const char * const &val) {
    auto res = 0;
    for (const auto & v: vec) {
        if (strcmp(v, val) == 0)
            ++res;
    }
    return res;
}


int main(int argc, char *argv[]) {
    const vector nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << count(nums, 1) << endl; // 2

    const vector prices = {1.1, 2.2, 3.3, 1.1, 5.5, 2.2, 3.3, -0.8, 9.9, 0.0};
    cout << count(prices, 1.1) << endl; // 2

    const vector<string> names = {"Mike", "Mike", "Jack", "Tom", "Ted"};
    cout << count(names, string("Mike")) << endl; // 2

    const vector prog_langs = {"C", "C++", "Java", "C", "C++", "C#", "Java", "C"};
    const auto target = "C";
    cout << count(prog_langs, target) << endl; // 3
}
