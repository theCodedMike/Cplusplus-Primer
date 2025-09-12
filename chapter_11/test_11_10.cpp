//
// Created by lixia on 2025/9/12.
//
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <map>
#include <numeric>

using namespace std;


int main(int argc, char *argv[]) {
    vector<int> iv = {1, 3, 5, 7, 1, 5};
    auto result = std::accumulate(
        iv.cbegin(), iv.cend(), map<int, int>(), [](map<int, int> acc, const int val) {
                ++acc[val];
                return acc;
            });

    for (auto &[fst, snd]: result) {
        cout << fst << ": " << snd << endl;
    }
    cout << endl;

    list<int> il = {1, 3, 5, 7, 1, 5};
    auto result2 = std::accumulate(
        il.cbegin(), il.cend(), map<int, int>(), [](map<int, int> acc, const int val) {
                ++acc[val];
                return acc;
            });

    for (auto &[fst, snd]: result2) {
        cout << fst << ": " << snd << endl;
    }
}
