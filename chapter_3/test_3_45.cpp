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
    for (auto &row: arr) {
        for (const auto cell: row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // 版本2
    for (auto i = 0; i < Row; ++i) {
        for (auto j = 0; j < Col; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // 版本3
    for (auto p = arr; p != arr + Row; ++p) {
        for (auto q = *p; q != *p + Col; ++q) {
            cout << *q << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // 版本4
    for (auto p = begin(arr); p != end(arr); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q) {
            cout << *q << ' ';
        }
        cout << endl;
    }
}
