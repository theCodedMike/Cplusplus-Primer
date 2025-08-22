//
// Created by lixia on 2025/8/22.
//
#include <iostream>

using std::cout;
using std::endl;
using std::begin;
using std::end;

int main(int argc, char *argv[]) {
    constexpr unsigned int Row = 2;
    constexpr unsigned int Col = 4;
    int arr[Row][Col] = {
        {1, 2, 3, 4},
        {10, 11, 12, 13}
    };

    // 版本1
    for (int (&r)[Col] : arr) {
        for (const int cell : r) {
            cout << cell << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // 版本2
    for (int i = 0; i < Row; ++i) {
        for (int j = 0; j < Col; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // 版本3
    for (int (*p)[Col] = arr; p != arr + Row; ++p) {
        for (int *q = *p; q != *p + Col; ++q) {
            cout << *q << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // 版本4
    for (int (*p)[Col] = begin(arr); p != end(arr); ++p) {
        for (int *q = begin(*p); q != end(*p); ++q) {
            cout << *q << ' ';
        }
        cout << endl;
    }
}
