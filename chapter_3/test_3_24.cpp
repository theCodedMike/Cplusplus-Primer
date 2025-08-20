//
// Created by lixia on 2025/8/20.
//

#include <iostream>
#include <vector>
#include "../include/Utils.h"
using std::vector;
using std::cin;
using std::cout;
using std::endl;


int main(int argc, char *argv[]) {
    vector<int> nums;
    int input;

    while (cin >> input)
        nums.push_back(input);

    cout << "Original: "; print_collection(nums);

    // 相邻之和
    for (auto beg = nums.cbegin(), end = nums.cend() - 1; beg < end; ++beg) {
        cout << (*beg + *(beg + 1)) << " ";
    }
    cout << endl;

    // 第n个和倒数第n个之和
    for (auto beg = nums.cbegin(), end = nums.cend() - 1; beg <= end; ++beg, --end) {
        cout << (*beg + *end) << " ";
    }
    cout << endl;
}
