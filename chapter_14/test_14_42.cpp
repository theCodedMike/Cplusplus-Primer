//
// Created by lixia on 2025/9/24.
//
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char *argv[]) {
    vector nums = {1, 2028, 3, 4, 5001, -45, 1000, 9999};
    const auto count = ranges::count_if(nums, bind(greater(), placeholders::_1, 1024));
    cout << count << endl; // 3
    cout << endl;

    vector<string> words = {"pooh", "pooh", "pooh", "c++", "pooh"};
    const auto iter = ranges::find_if(words, bind(not_equal_to(), placeholders::_1, "pooh"));
    if (iter != words.end())
        cout << *iter << endl; // c++
    cout << endl;

    vector ints = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ranges::transform(ints, ints.begin(), bind(multiplies(), placeholders::_1, 2));
    ranges::for_each(ints, [](const int i) { cout << i << " "; }); // 2 4 6 8 10 12 14 16 18 20
}
