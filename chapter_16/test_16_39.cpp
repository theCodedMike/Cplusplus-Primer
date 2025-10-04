//
// Created by lixia on 2025/10/4.
//
#include <iostream>
using namespace std;

template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main(int argc, char *argv[]) {
    const auto s1 = "hello";
    const auto s2 = "abc";

    const int result = compare<const char *>(s1, s2);
    cout << result << endl; // -1 // 比较的是2个指针的地址，而非字符串内容
}
