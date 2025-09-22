//
// Created by lixia on 2025/9/17.
//

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "../include/Sales_data.h"
#include "../include/StrVec.h"

using namespace std;

void use_right_ref();
void use_ref_qualifier();


int main(int argc, char *argv[]) {
    //use_right_ref();
    use_ref_qualifier();
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

StrVec get_vec(istream &);
StrVec get_vec(istream &is) {
    StrVec ret;
    string s;
    while (is >> s)
        ret.push_back(s);
    return ret;
}
void use_right_ref() {
    int i = 42;
    int &l = i; // ✔ i is an lvalue
    //int &&r = i; // ❌ cannot bind an rvalue ref to an lvalue
    //int &l2 = i * 42; // ❌ i * 42 is an rvalue
    const int &l3 = i * 42; // ✔
    int &&r2 = i * 42; // ✔

    //int &&r3 = r2; // ❌ r2是左值
    int &&r4 = std::move(r2);// ✔
    int &&r5 = std::move(i); // ✔ move告诉编译器，把i这个左值像右值一样处理

    StrVec v1, v2;
    v1 = v2; // v2是左值，使用拷贝赋值
    v2 = get_vec(cin); // get_vec返回一个右值，使用移动赋值
}

class Foo{
public:
    Foo sorted() &&; // 可用于可改变的右值
    [[nodiscard]]
    Foo sorted() const &; // 可用于任何类型的Foo

    using Comp = bool(const int&, const int&);
    Foo sorted(Comp *);
    Foo sorted(Comp *) const;

private:
    vector<int> data;
};

// 本对象是右值，所以可以原址排序
Foo Foo::sorted() && {
    std::ranges::sort(data.begin(), data.end());
    return *this;
}
// 本对象是const或是一个左值，不能原址排序
Foo Foo::sorted() const & {
    Foo ret(*this); // 拷贝一个副本
    std::ranges::sort(ret.data.begin(), ret.data.end());
    return ret; // 返回副本
}

Foo &ret_foo(); // 返回一个引用；ret_foo调用是一个左值
Foo &ret_foo() {
    static Foo foo;
    return foo;
}
Foo ret_val(); // 返回一个值；ret_val调用是一个右值
Foo ret_val() {
    return {};
}

void use_ref_qualifier() {
    Foo i, j; // i和j是左值
    i = j; // i是左值
    //ret_foo() = j; // ✔
    //ret_val() = j; // ❌，ret_val()返回一个右值
    //i = ret_val(); // ✔
    ret_val().sorted();
    ret_foo().sorted();
}