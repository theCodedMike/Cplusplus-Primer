//
// Created by lixia on 2025/9/11.
//
#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto crbegin = v.cend() - 1; crbegin >= v.cbegin(); --crbegin)
        cout << *crbegin << " ";
    // 9 8 7 6 5 4 3 2 1
}