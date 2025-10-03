//
// Created by lixia on 2025/10/3.
//

#include <deque>
#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

template <typename Container>
void print(const Container &v) {
    auto beg = v.begin();

    while (beg != v.end()) {
        cout << *beg << " ";
        ++beg;
    }
}
int main(int argc, char *argv[]) {
    const vector<int> nums = {1, 2, 3, 4, 5};
    print(nums); cout << endl;

    const list<string> prog_langs = {"C++", "Java", "Python", "C"};
    print(prog_langs); cout << endl;

    const deque<double> heights = {6.2, 6.4, 6.6, 6.8};
    print(heights); cout << endl;

    const set<char> chars = {'a', 'b', 'c', 'd'};
    print(chars);
}
