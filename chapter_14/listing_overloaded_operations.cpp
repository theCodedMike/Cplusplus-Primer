//
// Created by lixia on 2025/9/23.
//
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>

#include "../include/Sales_data.h"
#include "../include/StrBlob.h"
#include "../include/StrVec.h"

using namespace std;

class PrintString {
public:
    explicit PrintString(ostream &o = cout, const char c = ' ') : os(o), sep(c) {}
    void operator()(const string &s) const {
        os << s << sep;
    }

private:
    ostream &os;
    char sep;
};

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
    cout << endl;

    // 赋值运算符
    initializer_list<string> il = {"1", "2", "3"};
    StrVec sv = il;

    // 下标运算符
    cout << sv[0] << endl; // 1
    sv[0] = "-1";
    cout << sv[0] << endl; // -1
    cout << endl;

    // 递增/递减运算符
    const StrBlob sb({"1", "2", "3"});
    auto beg = sb.begin();
    ++beg;
    cout << beg << endl; // 2
    const auto curr = beg--;
    cout << beg << " " << curr << endl; // 1 2
    cout << endl;

    // 成员访问运算符
    *beg = "key";
    cout << beg->size() << " " << (*beg).size() << endl; // 3 3
    cout << endl;

    // 函数调用运算符
    struct AbsInt {
        int operator()(const int val) const {
            return val < 0 ? -val : val;
        }
    };
    constexpr AbsInt obj; // 函数对象
    cout << obj(-10) << " " << obj(10) << endl; // 10 10
    const PrintString printer;
    printer("hello"); cout << endl;
    const PrintString errors(cerr, '\n');
    //errors("bad alloc"); cout << endl;
    vector<string> nums = {"1", "2", "3", "4", "5"};
    std::ranges::for_each(nums, printer); // 1 2 3 4 5
    cout << endl;
    std::ranges::sort(nums, std::greater());
    std::ranges::for_each(nums, printer); // 5 4 3 2 1
    cout << endl;

    // function类型
    //普通函数
    int add(int i, int j);
    //lambda
    auto mod = [](const int i, const int j) {
        return i % j;
    };
    //函数对象
    struct divide {
        int operator()(const int denominator, const int divisor) const {
            if (divisor == 0)
                throw runtime_error("divide by zero");
            return denominator / divisor;
        }
    };
    function<int(int, int)> f1 = add; // 函数指针
    function<int(int, int)> f2 = divide(); // 函数对象
    function<int(int, int)> f3 = [](const int i, const int j) {
        return i * j;
    }; // lambda
    cout << f1(4, 2) << endl; // 6
    cout << f2(4, 2) << endl; // 2
    cout << f3(4, 2) << endl; // 8

    map<string, function<int(int, int)>> binops = {
        {"+", add}, // 函数指针
        {"-", minus()}, // 标准库函数对象
        {"/", divide()}, // 用户定义的函数对象
        {"*", [](const int i, const int j) {return i * j;}}, // 未命名的lambda
        {"%", mod} // 命名的lambda
    };
    cout << binops["+"](6, 2) << endl; // 8
}

int add(const int i, const int j) {
    return i + j;
}