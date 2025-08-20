//
// Created by lixia on 2025/8/20.
//

#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::endl;


int main(int argc, char *argv[]) {
    int input;
    vector<int> nums;

    while (cin >> input)
        nums.push_back(input);

    if (nums.size() < 2) {
        cout << nums[0] << endl;
        return 0;
    }

    for (int i = 0; i < nums.size() - 1; i++) {
        cout << nums[i] + nums[i + 1] << " ";
    }
    cout << endl;

    for (int i = 0, j = nums.size() - 1; i <= j; i++, j--) {
        cout << nums[i] + nums[j] << " ";
    }
    cout << endl;
}
