//
// Created by lixia on 2025/10/4.
//
#include <iostream>
#include <vector>
using namespace std;

template <typename It>
auto fcn3(It beg, It end) -> decltype(*(beg + 0)) { // 返回一个左值
    if (beg == end) {
        throw runtime_error("no elements in sequence");
    }
    return *beg; // 返回序列中一个元素的拷贝
}

template <typename It>
auto fcn4(It beg, It end) -> remove_reference_t<decltype(*(beg + 0))> { // 返回一个值
    if (beg == end) {
        throw runtime_error("no elements in sequence");
    }
    return *beg; // 返回序列中一个元素的拷贝
}

int main(int argc, char *argv[]) {
    vector<string> names = {"Larry", "Moe", "Curly"};

    const auto result = fcn3(names.begin(), names.end());
    cout << result << endl; // Larry

    const auto ret2 = fcn4(names.begin(), names.end());
    cout << ret2 << endl; // Larry
}
