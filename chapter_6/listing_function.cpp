//
// Created by lixia on 2025/8/27.
//

#include "../include/Chapter6.h"

void var_argc(...);
bool length_compare(const string &, const string &);


int main(int argc, char *argv[]) {
    // 函数基础
    int val = 5;
    cout << val << "! = " << fact(val) << endl;

    for (size_t i = 0; i != 10; ++i)
        cout << count_calls() << ' ';
    cout << endl << endl;

    // 参数传递
    int i = 42;
    reset_with_ptr(&i);
    cout << "now i = " << i << endl; // i = 0
    int j = 20;
    reset_with_ref(j); // 推荐使用引用
    cout << "now j = " << j << endl; // j = 0

    const string s = "keep out! ok?";
    string::size_type t = 0;
    cout << find_char(s, 'o', t) << ' ' << t << endl; // 5 2

    const string s2 = "hello world.";
    cout << is_sentence(s2) << endl << endl; // 1

    // 数组形参
    int arr2d[2][4] = {1,3,5,7,9,11,13,15};
    print_2d_array(arr2d, 2);

    // 含有可变形参的函数
    initializer_list<int> nums = {1, 4, -2, 2};
    for (auto beg = nums.begin(); beg != nums.end(); ++beg) {
        if (*beg < 0)
            ;//*beg = 10; // ❌ initializer_list是只读的
    }
    var_argc(3, "hello", "world", "ok", 3.4);
    cout << "5! = " << factorial(5) << endl; // 递归函数

    // 函数指针
    bool (*pf) (const string &, const string &);
    pf = length_compare; // 等价于pf = &length_compare;
    cout << pf("hello", "haha") << endl;
    cout << (*pf)("hello", "world") << endl;
    cout << length_compare("hello", "world") << endl;
}

int fact(int val) {
    int ret = 1;
    while (val > 1)
        ret *= val--;
    return ret;
}

size_t count_calls() {
    static size_t ctr = 0; // 调用结束后，这个值仍然有效
    return ++ctr;
}

void reset_with_ptr(int *ip) {
    *ip = 0;
}

void reset_with_ref(int &val) {
    val = 0;
}

string::size_type find_char(const string &s, const char c, string::size_type &occurs) {
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            if (ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

bool is_sentence(const string &s) {
    string::size_type ctr = 0;
    return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;
}

// 适用于C风格字符串
void print_c_style_string(const char *cp) {
    if (cp) {
        while (*cp)
            cout << *cp++;
        cout << endl;
    }
}

void print_with_iterator(const int *beg, const int *end) {
    while (beg != end)
        cout << *beg++;
    cout << endl;
}

void print_with_size(const int ia[], size_t size) {
    for (size_t i = 0; i != size; ++i)
        cout << ia[i];
    cout << endl;
}

// 注意：数组长度是形参的一部分
void print_with_ref(int (&arr)[10]) {
    for (auto &elem: arr) {
        cout << elem;
    }
    cout << endl;
}

// 等价于
void print_2d_array(int matrix[][4], const int row_size)
//void print_2d_array(int (*matrix)[4], const int row_size)
{
    for (size_t i = 0, col_size = size(*matrix); i != row_size; ++i, ++matrix) {
        for (size_t j = 0; j != col_size; ++j) {
            cout << (*matrix)[j] << ' ';
        }
        cout << endl;
    }
}

// 省略符形参只能出现在形参列表的最后一个位置
void var_argc(...) {

}

// 不要这么做
const string &manip() {
    string ret;

    if (ret.empty())
        return "Empty"; // ❌

    return ret; // ❌
}

int factorial(const int val) {
    if (val <= 1)
        return 1;

    return val * factorial(val - 1);
}

bool length_compare(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}