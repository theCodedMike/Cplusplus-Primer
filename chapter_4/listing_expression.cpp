//
// Created by lixia on 2025/8/23.
//

#include <iostream>
#include <vector>
using namespace std;

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

    // 成员访问运算符
    string s1 = "a string", *p = &s1;
    cout << s1.size() << ' ';
    cout << p->size() << ' ';
    cout << (*p).size() << endl; // 8 8 8

    // 条件运算符
    int grade = 6;
    grade = 10;
    string result = grade < 60 ? "fail" : "pass";
    result = grade > 90 ? "high pass" : grade < 60 ? "fail" : "pass";

    // sizeof
    cout << sizeof(byte) << endl;  // 1
    cout << sizeof(char) << endl;  // 1
    cout << sizeof(short) << endl; // 2
    cout << sizeof(int) << endl;   // 4
    cout << sizeof(long) << endl;  // 4
    cout << sizeof(long long) << endl;  // 8
    cout << sizeof(float) << endl;      // 4
    cout << sizeof(double) << endl;     // 8
    cout << sizeof(long double) << endl;// 16
    cout << endl;
    int a = 55;
    int *pA = &a;
    int &rA = a;
    cout << sizeof(pA) << endl; // 8
    cout << sizeof(*pA) << endl;// 4
    cout << sizeof(rA) << endl; // 4
    cout << endl;

    int arr[5] = {1, 2, 3, 4, 5};
    cout << sizeof(arr) << endl; // 20
    cout << (sizeof(arr) / sizeof(*arr)) << endl; // 5
    cout << endl;

    vector<int> vec = {1, 2, 3, 4, 5};
    cout << sizeof(vec) << ' ' << vec.size() << ' ' << vec.capacity() << endl; // 24 5 5
    cout << endl;

    string s = "hello";
    cout << sizeof(s) << ' ' << s.size() << ' ' << s.capacity() << endl; // 32 5 15
}
