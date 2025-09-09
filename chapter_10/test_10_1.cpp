//
// Created by lixia on 2025/9/9.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(int argc, char *argv[]) {
    const vector<int> nums = {-23, 9, 999, -45, 3, 9, 1000, -9, 9};
    constexpr int target = 9;

    const ptrdiff_t result = ranges::count(nums, target);
    cout << result << endl; // 3
}
