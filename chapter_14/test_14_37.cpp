//
// Created by lixia on 2025/9/24.
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class CmpInt {
public:
    bool operator()(const int i1, const int i2) const {
        return i1 == i2;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {0, -7, 0, 9, 33, -6, 0, -20};
    const CmpInt cmp;
    const int target = 0;
    const int new_val = 10;

    std::ranges::replace_if(nums, [&](const int n) {
        return cmp(n, target);
    }, new_val);

    std::ranges::for_each(nums, [](const int n) {
        cout << n << " ";
    });
}
