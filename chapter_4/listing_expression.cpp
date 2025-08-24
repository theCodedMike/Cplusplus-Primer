//
// Created by lixia on 2025/8/23.
//

#include <iostream>
#include <vector>

#include "../include/Utils.h"
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
    cout << endl;

    // 逗号运算符
    int x = (i = 10, j = 20, k = 30, i + j + k);
    cout << x << endl; // 60
    vector<int> grades(10, 0);
    int first = 100;
    for (size_t i = 0; i < grades.size(); ++i, --first)
        grades[i] = first;
    print_collection(grades); // [100, 99, 98, 97, 96, 95, 94, 93, 92, 91]
    cout << endl;

    // 类型转换
    bool flag; char cVal;
    short sVal; unsigned short usVal;
    int iVal; unsigned int uiVal;
    long lVal; unsigned long ulVal;
    float fVal; double dVal;
    3.14159L + 'a'; // ‘a'提升成int，然后该int转换成long double
    dVal + iVal; // iVal转换成double
    dVal + fVal; // fVal转换成double
    iVal = dVal; // dVal转换成int
    flag = dVal; // 如果dVal是0,则flag是false；否则为true
    cVal + fVal; // cVal提升成int，然后该int转换成float
    sVal + cVal; // sVal和cVal提升成int
    cVal + lVal; // cVal转换成long
    iVal + ulVal; // iVal提升成unsigned long
    usVal + iVal; // 根据unsigned short和int所占空间大小进行提升
    uiVal + lVal; // 根据unsigned int和long所占空间大小进行提升

    // 类型转换
    int w = 10;
    double slope = static_cast<double>(w) / i;
    void *pW = &w;
    int *dp = static_cast<int *>(pW);

    const char *pc;
    char *pd = const_cast<char *>(pc);

    int *ip;
    char *pr = reinterpret_cast<char *>(ip); // pr指向一个int而非char

}
