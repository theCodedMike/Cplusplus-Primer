//
// Created by lixia on 2025/9/6.
//

#include <iostream>
#include <vector>
#include "../include/Utils.h"
using namespace std;

bool find(vector<int>::const_iterator begin, vector<int>::const_iterator end, const int &target) {
    while (begin != end) {
        if (*begin == target)
            return true;
        ++begin;
    }
    return false;
}

int main(int argc, char *argv[]) {
    std::vector<int> nums = {-9, 22, 853, 34, -71, 1000};
    const int target = 1000;

    const bool is_find = find(nums.cbegin(), nums.cend(), target);

    print_collection(nums);
    cout << "find " << target << ": " << (is_find ? "yes" : "no") << endl;
}

