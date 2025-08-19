//
// Created by lixia on 2025/8/19.
//

#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;


int main(int argc, char *argv[]) {
    vector<int> nums;
    int input;

    while (cin >> input)
        nums.push_back(input);

    for (auto num: nums) {
        cout << num << " ";
    }
}
