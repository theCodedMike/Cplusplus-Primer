//
// Created by lixia on 2025/10/1.
//
#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;


template <typename Iter, typename T>
pair<bool, Iter> find(Iter beg, Iter end, const T &val) {
    while (beg != end) {
        if (*beg == val)
            return make_pair(true, beg);
        ++beg;
    }

    return make_pair(false, end);
}


int main(int argc, char *argv[]) {
    const vector<int> vi = {-10, 33, 259, 76, -3, 44, 100};
    const list<string> ls = {"hello", "world", "c++", "c", "java"};

    if (auto [found, pos] = find(vi.cbegin(), vi.cend(), 33); found)
        cout << *pos << endl; // 33
    if (auto [found, pos] = find(vi.cbegin(), vi.cend(), 34); found)
        cout << *pos << endl;

    if (auto [found, pos] = find(ls.cbegin(), ls.cend(), "c++"); found)
        cout << *pos << endl; // c++
    if (auto [found, pos] = find(ls.cbegin(), ls.cend(), "rust"); found)
        cout << *pos << endl;
}
