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

    vector<int> stat(11, 0);
    auto beg = stat.begin();
    for (int num: nums) {
        if (num <= 100)
            *(beg + num / 10) += 1;
    }

    cout << "Statistics: "; print_collection(stat);
}
