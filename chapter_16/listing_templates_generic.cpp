//
// Created by lixia on 2025/9/29.
//

#include <iostream>
#include <string>
#include <cstring>

#include "../include/Blob.h"

using namespace std;


void function_template();
void class_template();


int main(int argc, char *argv[]) {
    //function_template();
    class_template();

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