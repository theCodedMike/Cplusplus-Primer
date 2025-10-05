//
// Created by lixia on 2025/10/5.
//
#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <map>
#include <numeric>
#include <vector>

#include "../include/Sales_data.h"
#include "../include/Utils.h"

using namespace std;


void use_tuple();


int main(int argc, char *argv[]) {
    use_tuple();
}

void use_tuple() {
    // 定义和初始化
    tuple<size_t, string, int> t1;
    tuple<size_t, string, int> t2 = {5, "C++", 2025};
    tuple<size_t, string, int> t3(5, "C++", 2025);
    auto t4 = make_tuple(5, "C++", 2025);
    print_tuple(t1);
    print_tuple(t2);
    print_tuple(t3);
    print_tuple(t4);


    // 遍历
    constexpr auto len = tuple_size_v<decltype(t4)>;
    cout << "tuple size: " << len << endl; // 3
    /*
    // 不能这么遍历，因为get<i>的i是编译时常量，不能在运行时动态获取
    for (auto i = 0; i < len; ++i)
        cout << get<i>(t4) << endl;
    */
    cout << std::get<0>(t4) << " " << std::get<1>(t4) << " " << std::get<2>(t4) << endl;
    std::get<2>(t4) += 1;
    print_tuple(t4); // [5, C++, 2026]

    // 比较
    cout << "t1 == t2: " << (t1 == t2) << endl; // 0
    cout << "t2 == t3: " << (t2 == t3) << endl; // 1
    cout << "t3 < t4: " << (t3 < t4) << endl; // 1

    //unordered_map<decltype(t3), int> umap; //
    map<decltype(t3), int> map;
    map[t3] = 5;
    map[t3] = 10;
    cout << "map[t3]: " << map[t3] << endl; // 10
}

typedef tuple<
    vector<Sales_data>::size_type,
    vector<Sales_data>::const_iterator,
    vector<Sales_data>::const_iterator
> matches;

vector<matches> find_book(const vector<vector<Sales_data>> &files, const string &book) {
    vector<matches> ret;

    for (auto iter = files.cbegin(); iter != files.cend(); ++iter) {
        auto [fst, snd] =
            std::equal_range(iter->cbegin(), iter->cend(), book, compare_isbn);
        if (fst != snd)
            ret.emplace_back(iter - files.cbegin(), fst, snd);
    }

    return ret;
}

void report_results(istream &in, ostream &os, const vector<vector<Sales_data>> &files) {
    string s; // 要查找的书
    while (in >> s) {
        auto trans = find_book(files, s);
        if (trans.empty()) {
            cout << s << " not found in any stores" << endl;
            continue;
        }

        for (const auto &store: trans) {
            os << "store " << get<0>(store) << " sales: "
               << accumulate(get<1>(store), get<2>(store), Sales_data(s))
               << endl;
        }
    }
}