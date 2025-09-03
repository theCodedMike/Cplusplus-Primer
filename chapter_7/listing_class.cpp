//
// Created by lixia on 2025/9/2.
//

#include <iostream>

#include "../include/Sales_data.h"
#include "../include/Screen.h"
using namespace std;

// 这是一个聚合类
struct Data {
    int i_val;
    string s;
};

int main(int argc, char *argv[]) {
    Screen myScreen(5, 3);
    const Screen blank(5, 3);

    myScreen.set('#').display(cout); // 调用非常量版本
    blank.display(cout); // 调用常量版本

    // 隐式的类类型转换
    Sales_data item("ISBN-911", 10, 20.3);
    string null_book = "ISBN-911";
    item.combine(null_book); // 这里有隐式的类类型转换
    //item.combine(string("ISBN-911"));   // 隐式地转换成sales_data
    //item.combine(Sales_data("ISBN-911")); // 显式地转换成Sales_data

    // 聚合类
    Data val1 = {0, "Hello"};
}