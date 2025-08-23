//
// Created by lixia on 2025/8/23.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include "../include/Utils.h"

using std::vector;
using std::cout;
using std::endl;
using std::for_each;

int main(int argc, char *argv[]) {
    vector<int> nums = {1, 1, 1, 4, 4, 4, 5, 5, 5};

    for (int &num: nums) {
        num = num % 2 == 0 ? num : num * 2;
    }
    print_collection(nums);

    /*
    for_each(nums.begin(), nums.end(),
        [](int &num) {num = num % 2 == 0 ? num : num * 2;});
    for_each(nums.begin(), nums.end(),
        [](const int num) {cout << num << " ";});
    */
}
