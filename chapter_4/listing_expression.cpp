//
// Created by lixia on 2025/8/23.
//

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;


int main(int argc, char *argv[]) {
    // 赋值运算符
    int i = 0, j = 0, k = 0;  // 初始化而非赋值
    const int ci = i;         // 初始化而非赋值
    i = 42;

    // 递增递减运算符
    int m = 0, n;
    n = ++m; // n = 1, m = 1  m先自增1，然后再赋值给n
    n = m++; // n = 0, m = 1  m先赋值给n，然后m自增1
    vector<int> nums = {1, 2, 3, 4, 5};
    for (auto beg = nums.begin(); beg != nums.end();) {
        cout << *beg++ << ' ';
    }
    cout << endl;
}
