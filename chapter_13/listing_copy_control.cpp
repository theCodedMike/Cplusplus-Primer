//
// Created by lixia on 2025/9/17.
//

#include <memory>
#include <string>
#include <vector>

#include "../include/Sales_data.h"

using namespace std;

int main(int argc, char *argv[]) {

}

// 拷贝构造函数
void use_copy_constructor() {
    string dots(10, '.'); // 直接初始化，选择最匹配的构造函数
    string s(dots);        // 直接初始化
    string s2 = dots;                 // 拷贝初始化，将右侧的对象拷贝给左侧正在创建的对象，这里使用'拷贝构造函数'来实现
    string null_book = "9999=0000";      // 拷贝初始化
    string nines = string(100, '9'); // 拷贝初始化
}
// 拷贝赋值运算符
void use_copy_assignment_operator() {

}

void use_destructor() {
    {
        Sales_data * p = new Sales_data(); // p是一个内置指针
        auto p2 = make_shared<Sales_data>(); // p2是一个shared_ptr
        Sales_data item(*p); // 拷贝构造函数将*p拷贝到item中
        vector<Sales_data> vec; // 局部对象
        vec.push_back(*p2); // 拷贝p2指向的对象
        delete p; // 对p指向的对象执行析构函数
    } // 退出局部作用域，对item、p2、vec调用析构函数
    // 销毁vec会销毁它的元素
}

void use_no_copy() {
    struct NoCopy {
        NoCopy() = default;  // 使用合成的默认构造函数
        NoCopy(const NoCopy&) = delete;            // 阻止拷贝
        NoCopy& operator=(const NoCopy&) = delete; // 阻止赋值
        ~NoCopy() = default; // 使用合成的析构函数
    };
}