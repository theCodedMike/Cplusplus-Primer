//
// Created by lixia on 2025/8/19.
//

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

void initialize();

void push_back();

int main(int argc, char *argv[]) {
    // 初始化
    //initialize();
    // 添加
    push_back();
}

void initialize() {
    vector<int> v1; // v1是一个空的vector
    vector<int> v2(v1); // v2中包含v1所有元素的副本
    vector<int> v3 = v1; // 等价于 v3(v1)

    vector<int> v4(10, 6); // v4包含10个值为6的元素
    vector<int> v5(20); // v5包含20个值为0的元素

    vector<int> v6{-2, 29, 25, 98};
    vector<int> v7 = {-2, 29, 25, 98}; // v7和v6是等价的
}

// 2倍扩容原则
void push_back() {
    vector<int> nums;
    nums.reserve(100); // 提前分配100个int空间，避免扩容
    for (int i = 0; i < 109; i++) {
        nums.push_back(i);
        cout << nums.size() << " " << nums.capacity() << endl;
    }

    for (auto num: nums) {
        cout << num << " ";
        if (num > 0 && num % 10 == 9)
            cout << endl;
    }
}
