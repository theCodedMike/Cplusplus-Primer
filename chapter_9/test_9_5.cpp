//
// Created by lixia on 2025/9/6.
//

#include <iostream>
#include <vector>
#include "../include/Utils.h"
using namespace std;

vector<int>::const_iterator find(vector<int>::const_iterator begin, vector<int>::const_iterator end, const int &target) {
    while (begin < end) {
        if (*begin == target)
            return begin;

        ++begin;
    }

    return end;
}


int main(int argc, char *argv[]) {
    std::vector<int> nums = {-9, 22, 853, 34, -71, 1000};
    const int target = 1000;
    auto cbegin = nums.cbegin();
    auto cend = nums.end();
    auto is_find = find(cbegin, cend, target);

    print_collection(nums);
    cout << "find " << target << ": " << (is_find != cend ? "yes" : "no") << endl;
}
