//
// Created by lixia on 2025/8/23.
//
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main(int argc, char *argv[]) {
    vector<int> nums = {1, 2, 3, 4, 5};

    for (auto beg = nums.begin(); beg != nums.end();) {
        cout << *++beg << ' ';
    }

    cout << endl; // 2 3 4 5 0
}
