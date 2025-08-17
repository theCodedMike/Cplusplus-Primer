//
// Created by lixia on 2025/8/16.
//

#include <iostream>

int get_size() {
    return 100;
}

constexpr int get_size2() {
    return 100;
}

int main(int argc, char *argv[]) {
    const int bufSize = 512; // const
    const int i = get_size(); // ✔ 运行时初始化
    const int j = 52; // ✔ 编译时初始化
    //const int k; // ❌ k未初始化

    const int ci = 3333;
    const int &r1 = ci; // ✔ r1是ci的引用
    //r1 = 42;          // ❌ r1是ci的引用，不能赋值
    //int &r2 = ci;     // ❌ ci是const，不能绑定到非const引用

    int k = 52;
    const int &rK1 = k; // 允许将const int&绑定到一个普通int对象上
    const int &rK2 = 42; // ✔ rK2是一个常量引用
    const int &rK3 = rK1 * 2; // ✔ rK3是一个常量引用
    //int &rK4 = rK1 * 2; // ❌ rK4是一个普通的非常量引用

    double dVal = 42.52;
    const int &rDVal = dVal; // ✔ rDVal是一个常量引用
    std::cout << rDVal << std::endl; // 42

    const double pi = 3.14159; // pi是一个常量，其值不能改变
    //double *pPi = &pi; // ❌ pPi是一个普通指针
    const double *pPi = &pi; // ✔ pPi是一个常量指针
    //*pPi = 9.22; // ❌ 不能给*pPi赋值

    float length = 9.8;
    const float *pLen = &length;
    //*pLen = 10; // ❌ 不能给*pLen赋值

    // const指针 不变的是指针本身的值而非指向的那个值
    int errNumb = 0;
    int *const curErr = &errNumb;   // curErr将一直指向errNumb
    const double eVal = 2.71828;
    const double *const pE = &eVal; // pE是一个常量指针，将一直指向eVal

    // 顶层const
    int tp = 20;
    int *const tpPtr = &tp; // 不能改变tpPtr的值，这是一个顶层const
    const int mk = 29;      // 不能改变mk的值，这是一个顶层const
    const int *mkPtr = &mk; // 允许改变mkPtr的值，这是一个底层const
    const int *const mkPtr2 = mkPtr; // 左边的是底层const，右边的是顶层const
    const int &r = mk; // 用于声明引用的const是底层const

    // 常量表达式
    const int max_files = 20; // max_files是常量表达式
    const int limit = max_files + 1; // limit是常量表达式
    int staff_size = 27; // staff_size不是常量表达式，是一个普通int类型而非const int
    const int sz = get_size(); // sz不是常量表达式，它的值需要在运行时才能计算出

    constexpr int mf = 30;
    constexpr int limit2 = mf + 1;
    constexpr int sz2 = get_size2();
    // constexpr只对指针有效，对指针所指的对象无效
    const int *p = nullptr; // p是一个指向整型常量的指针
    constexpr int *q = nullptr; // q是一个指向整数的常量指针

    return 0;
}


