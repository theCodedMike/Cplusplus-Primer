//
// Created by lixia on 2025/8/19.
//

#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

void initialize();
void push_back();
void modify_vector();
void count_grade();

int main(int argc, char *argv[]) {
    // 初始化
    //initialize();
    // 添加
    //push_back();
    // 其他操作
    //modify_vector();
    count_grade();
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

void modify_vector() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int & num: nums) {
        num *= num;
    }
    for (int num: nums) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> v1 = {1, 2};
    vector<int> v2 = {1, 2, 3};
    vector<int> v3 = {2, 1};
    cout << (v2 > v1) << endl; // 1
    cout << (v3 > v2) << endl; // 1
}

// 以10分为一个分数段统计成绩的数量
// 0~9 10~19 20~29 30~39 40~49 50~59 60~69 70~79 80~89 90~99 100
void count_grade() {
    vector<unsigned> scores(11, 0);
    unsigned grade;
    while (cin >> grade)
        if (grade <= 100)
            scores[grade / 10]++;
}