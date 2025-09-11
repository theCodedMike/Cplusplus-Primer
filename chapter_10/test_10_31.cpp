//
// Created by lixia on 2025/9/11.
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    istream_iterator<int> is_iter(cin), eof;
    vector<int> nums;

    while (is_iter != eof) {
        nums.push_back(*is_iter++);
    }

    std::ranges::sort(nums);

    const ostream_iterator<int> os_iter(cout, " ");
    std::ranges::unique_copy(nums, os_iter);
}
