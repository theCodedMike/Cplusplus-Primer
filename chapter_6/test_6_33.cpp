//
// Created by lixia on 2025/8/28.
//
#include "./../include/Chapter6.h"

void print(const vector<int> &vec, size_t size);

int main(int argc, char *argv[]) {
    const vector<int> nums = {-9, 33, 100, 51, 77, 986, -92};
    print(nums, nums.size());
}

void print(const vector<int> &vec, const size_t size) {
    if (size == 1) {
        cout << vec[size - 1] << ' ';
        return;
    }

    print(vec, size - 1);

    cout << vec[size - 1] << ' ';
}
