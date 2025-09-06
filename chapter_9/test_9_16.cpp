//
// Created by lixia on 2025/9/6.
//
#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool compare(const vector<int> &v, const list<int> &l);

int main(int argc, char *argv[]) {
    vector<int> v = {3, 2, 1};
    list<int> l1 = {1, 2, 3};
    list<int> l2 = {3, 2, 1};
    list<int> l3 = {3, 2, 1, 0};
    cout << compare(v, l1) << endl; // false
    cout << compare(v, l2) << endl; // true
    cout << compare(v, l3) << endl; // false
}

bool compare(const vector<int> &v, const list<int> &l) {
    auto l_beg = l.cbegin();
    const auto l_end = l.cend();
    if (const auto l_size = std::distance(l_beg, l_end); v.size() != l_size)
        return false;

    auto v_beg = v.cbegin();
    const auto v_end = v.end();

    do {
        if (*l_beg != *v_beg)
            return false;
        ++l_beg;
        ++v_beg;
    } while (v_beg != v_end);

    return true;
}