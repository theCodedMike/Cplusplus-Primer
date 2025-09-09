//
// Created by lixia on 2025/9/9.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    char c_str1[] = "hello";
    char c_str2[] = "world";
    char c_str3[] = "c++";
    vector<char *> v1, v2;
    v1.push_back(c_str1); v2.push_back(c_str1);
    v1.push_back(c_str2); v2.push_back(c_str2);
    v1.push_back(c_str3);

    const bool v1_equal_v2 = std::equal(v1.cbegin(), v1.cend(), v2.cbegin());
    cout << v1_equal_v2 << endl; // 0
    const bool v2_equal_v1 = std::equal(v2.cbegin(), v2.cend(), v1.cbegin());
    cout << v2_equal_v1 << endl; // 1
}
