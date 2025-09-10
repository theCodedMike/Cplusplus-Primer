//
// Created by lixia on 2025/9/9.
//
#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include "../include/Utils.h"

using namespace std;

void elim_dups(vector<string> &);
void fcn1();
void fcn2();
void fcn3();
void fcn4();
bool check_size(const string &, string::size_type);


int main(int argc, char *argv[]) {
    // 只读算法
    vector<int> nums = {11, -9, 345, -90, 71, 33, 2, -9, 0, 0, 121, 0};
    const auto find = std::ranges::find(nums, 0);
    cout << (find != nums.cend() ? "find" : "dont find") << endl; // find

    const auto count = std::ranges::count(nums, 0);
    cout << count << endl; // 3

    const int sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
    cout << sum << endl; // 475

    const vector<string> names = {"Mike", "John", "Bill"};
    const auto acc_names = std::accumulate(names.cbegin(), names.cend(), string(""));
    cout << acc_names << endl; // MikeJohnBill

    const vector<int> v1 = {1, 3, 5}; const vector<int> v2 = {1, 3, 5, 1};
    const bool equal = std::equal(v1.cbegin(), v1.cend(), v2.cbegin());
    cout << (equal ? "equal" : "not equal") << endl; // equal
    cout << endl;


    // 写算法
    vector<int> v3(10, 0);
    std::fill(v3.begin(), v3.end(), 3);
    print_collection(v3); // [3, 3, 3, 3, 3, 3, 3, 3, 3, 3]
    std::fill(v3.begin(), v3.begin() + 5, 5);
    print_collection(v3); // [5, 5, 5, 5, 5, 3, 3, 3, 3, 3]
    std::fill_n(v3.begin(), 3, 7);
    print_collection(v3); // [7, 7, 7, 5, 5, 3, 3, 3, 3, 3]
    vector<int> v4;
    //std::fill_n(v4.begin(), 10, 1); // 异常终止
    std::fill_n(back_inserter(v4), 10, 1);
    print_collection(v4); // [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]

    int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a2[std::size(a1)];
    std::copy(std::begin(a1), std::end(a1), a2);
    print_collection(a2); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    std::replace(std::begin(a1), std::end(a1), 0, -1);
    print_collection(a1); // [-1, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    vector<int> v5;
    std::replace_copy(std::cbegin(a1), std::cend(a1), back_inserter(v5), -1, 0);
    print_collection(v5); // [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]


    // 排序
    vector<string> v6 = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elim_dups(v6);
    print_collection(v6); // [fox, jumps, over, quick, red, slow, the, turtle]
    cout << endl;

    // lambda
    auto f = [] {return 42;};
    cout << f() << endl;
    auto sz = 5;
    const auto wc = find_if(
        v6.cbegin(), v6.cend(), [sz](const string &s) {return s.size() >= sz;});
    for_each(
        wc,v6.cend(),[](const string &s) {cout << s << " ";}); // jumps over quick red slow the turtle
    cout << endl;
    fcn1(); //值捕获
    fcn2(); //引用捕获
    fcn3(); //可变lambda
    fcn4();
    vector<int> v7 = {-5, 3, -9, 6, 0, -1};
    ranges::transform(v7, v7.begin(), [](const int i) {
        if (i < 0)
            return -i;
        return i;
    });
    print_collection(v7);
    //参数绑定
    auto check6 = std::bind(check_size, placeholders::_1, 6);
    cout << check6("fuckyou") << endl; //1
    cout << check6("fuck") << endl; // 0
}

void elim_dups(vector<string> &words) {
    ranges::sort(words);
    const auto end_unique = std::unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elim_dups(words);// 将words按字典序排序，删除重复单词
    stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {return a.size() < b.size();});
    const auto wc = find_if(words.begin(), words.end(), [sz](const string &a) {return a.size() >= sz;});
    for_each(wc, words.end(), [](const string &s) {cout << s << " ";});
    cout << endl;
}

// 值捕获
void fcn1() {
    size_t fcn1 = 42;
    auto f = [fcn1] {
        return fcn1;
    };

    fcn1 = 0;
    cout << "fcn1 = " << fcn1 << ", f() = " << f() << endl; // fcn1 = 0, f() = 42
}

void fcn2() {
    size_t fcn2 = 42;
    auto f = [&fcn2] {
        return fcn2;
    };

    fcn2 = 0;
    cout << "fcn2 = " << fcn2 << ", f() = " << f() << endl; // fcn2 = 0, f() = 0
}

void fcn3() {
    size_t fcn3 = 42;
    auto f = [fcn3] () mutable {
        return ++fcn3;
    };

    fcn3 = 0;
    cout << "fcn3 = " << fcn3 << ", f() = " << f() << endl; // fcn3 = 0, f() = 43
}

void fcn4() {
    size_t fcn4 = 42;
    auto f = [&fcn4] {
        return ++fcn4;
    };

    fcn4 = 0;
    cout << "fcn4 = " << fcn4 << ", f() = " << f() << endl; // fcn4 = 0, f() = 1
}

bool check_size(const string &s, const string::size_type sz) {
    return s.size() >= sz;
}

