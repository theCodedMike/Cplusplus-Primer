//
// Created by lixia on 2025/9/23.
//
#include <iostream>

#include "../include/Sales_data.h"
#include "../include/StrBlob.h"
#include "../include/StrVec.h"

using namespace std;


int main(int argc, char *argv[]) {
    // 输入和输出运算符
    //Sales_data sd;
    //cin >> sd;
    //cout << sd;

    // 算术和关系运算符
    const Sales_data sd1("ISBN-911", 10, 12.5);
    const Sales_data sd2("ISBN-911", 11, 15);
    cout << (sd1 == sd2) << endl; // 0
    auto sd3 = sd1 + sd2;
    cout << sd3 << endl;
    sd3 += sd1;
    cout << sd3 << endl;

    // 赋值运算符
    initializer_list<string> il = {"1", "2", "3"};
    StrVec sv = il;

    // 下标运算符
    cout << sv[0] << endl; // 1
    sv[0] = "-1";
    cout << sv[0] << endl; // -1

    // 递增/递减运算符
    const StrBlob sb({"1", "2", "3"});
    auto beg = sb.begin();
    ++beg;
    cout << beg << endl; // 2
    const auto curr = beg--;
    cout << beg << " " << curr << endl; // 1 2
}
