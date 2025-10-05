//
// Created by lixia on 2025/9/29.
//

#include <iostream>
#include <string>
#include <cstring>

#include "../include/Blob.h"
#include "../include/Sales_data.h"

using namespace std;


void function_template();
void class_template();
void deduce_template_argument();
void variadic_templates();
void template_specialization();

int main(int argc, char *argv[]) {
    //function_template();
    //class_template();
    //deduce_template_argument();
    //variadic_templates();
    template_specialization();
}

template <typename T>
int compare(const T &v1, const T &v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}
template <typename T, class U>
void calc(const T &v1, const U &v2) {
    // typename和class没有区别
    // 如果有多个类型参数，不能省略   "typename T, U"这样写是错误的
}
template <unsigned N, unsigned M>
int compare2(const char (&s1)[N], const char (&s2)[M]) {
    return strcmp(s1, s2);
}
template <typename T>
int compare3(const T &v1, const T &v2) {
    if (std::less<T>()(v1, v2))
        return -1;
    if (std::less<T>()(v2, v1))
        return 1;
    return 0;
}
void function_template() {
    cout << compare<string>("Hello, World!", "Hello, C++!") << endl; // 1
    cout << compare<int>(42, 42) << endl; // 0

    cout << compare2("hi", "mom") << endl; // -1

    cout << compare3("hello", "lello") << endl; // 1
}

void class_template() {
    Blob ib = {1, 4, -10};
    const initializer_list<string> is = {"hello", "world", "c++", "java"};
    Blob sb(is);
    for (auto i = 0; i < sb.size(); ++i)
        cout << sb[i] << " ";
    cout << endl;
    cout << sb << endl;
}

// 模板实参推断
template <typename T> void f1(T &) {}
template <typename T> void f2(const T&) {}
template <typename T> void f3(T &&) {}
void deduce_template_argument() {
    int i = 10;
    const int ci = 10;

    f1(i); // i是一个int；模板参数类型T是int
    f1(ci); // ci是一个const int；模板参数T是const int
    //f1(5); // ❌ 传递给一个&参数的实参必须是一个左值

    f2(i); // i是一个int；模板参数T是int
    f2(ci); // ci是一个const int，但模板参数T是int
    f2(5); // 一个const &参数可以绑定到一个右值；T是int

    f3(5); // 实参是一个int类型的右值；模板参数T是int
}

// Args是一个模板参数包；rest是一个函数参数包
// Args表示0或多个模板类型参数
// rest表示0或多个函数参数
template <typename T, typename... Args>
void foo(const T &t, const Args &... rest) {
    cout << t << endl;
    cout << sizeof...(Args) << endl; // 类型参数的数目
    cout << sizeof...(rest) << endl;
}

// 用来终止递归并打印最后一个元素的函数
template <typename T>
ostream &print(ostream &os, const T &t) {
    os << t;
    return os;
}
template <typename T, typename... Args>
ostream &print(ostream &os, const T &t, const Args&... rest) { // 扩展Args
    os << t << ", "; // 打印第一个实参
    return print(os, rest...); // 递归调用，打印其他实参      // 拓展rest
}
void variadic_templates() {
    int i = 0; double d = 3.14; string s = "hello world";
    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");
    // output:
    // 0
    // 3
    // 3
    // hello world
    // 2
    // 2
    // 3.14
    // 1
    // 1
    // hi
    // 0
    // 0
    cout << endl;

    print(cout, i, s, 42, d); // 0, hello world, 42, 3.14
}

// compare的特例化版本，只处理字符数组的指针
template <>
int compare(const char *const &p1, const char *const &p2) {
    return strcmp(p1, p2);
}
void template_specialization() {
    const char *p1 = "hi", *p2 = "hello";
    cout << compare(p1, p2) << endl; // 调用特例版本
    cout << compare2("hi", "hello") << endl;
}
