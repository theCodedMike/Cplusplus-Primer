//
// Created by lixia on 2025/8/22.
//

#include <array>
#include <iostream>
#include <memory>
#include <vector>
using std::vector;
using std::array;
using std::size_t;
using std::cout;
using std::endl;
using std::begin;
using std::end;


void initialize();
void traverse();
void container_array();
void jagged_array();

int main(int argc, char *argv[]) {
    //initialize();
    //traverse();
    //container_array();
    jagged_array();
}

void initialize() {
    int ia[3][4] = {
        {0, 1, 2, 3}, // 第1行的初始值
        {4, 5, 6, 7}, // 第2行的初始值
        {8, 9, 10, 11}// 第3行的初始值
    };

    int ia2[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // 和前一个是等价的

    int ia3[3][4] = {
        {0}, {4}, {8}
    }; // 只显示初始化每行的第1个元素，其他元素为0

    int ia4[3][4] = {0, 1, 2, 3}; // 只显示初始化了第1行，其他行都是0
}

void traverse() {
    constexpr size_t Row = 3, Col = 4;
    int ia[Row][Col];
    for (size_t i = 0; i != Row; ++i) {
        for (size_t j = 0; j != Col; ++j) {
            ia[i][j] = i * Col + j;
            cout << ia[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (auto &r: ia) { // 外城必须是引用类型
        for (auto cell : r) {
            cout << cell << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (auto i = ia; i != ia + Row; ++i) {
        for (auto j = *i; j != *i + Col; ++j) {
            cout << *j << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i != Row; ++i) {
        auto p = &ia[i];
        for (int j = 0; j != Col; ++j) {
            cout << *(*p + j) << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (auto i = begin(ia); i != end(ia); ++i) {
        for (auto j = begin(*i); j != end(*i); ++j) {
            cout << *j << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // 类型别名简化多维数组的指针
    using int_array = int[4];
    //typedef int int_array[4]; // 等价于上面的
    for (int_array *p = ia; p != ia + Row; ++p) {
        for (auto q = *p; q != *p + Col; ++q) {
            cout << *q << ' ';
        }
        cout << endl;
    }
}

void container_array() {
    // 2行4列
    const array<array<int, 4>, 2> nums = {
        1, 2, 3, 4,
        5, 6
    };

    for (auto &row: nums) {
        for (const int cell: row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i != nums.size(); ++i) {
        for (int j = 0; j != nums[i].size(); ++j) {
            cout << nums[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    for (auto p = nums.begin(); p != nums.end(); ++p) {
        for (auto q = p->begin(); q != p->end(); ++q) {
            cout << *q << ' ';
        }
        cout << endl;
    }
}

// 交错数组
void jagged_array() {
    // 实现方式1 —— 指针数组
    int* pArray[3];
    pArray[0] = new int[]{0, 1, 2, 3};
    pArray[1] = new int[]{4, 5};
    pArray[2] = new int[]{6, 7, 8, 9, 10, 11};

    // 实现方式2 —— std::vector  推荐✔
    vector<vector<int>> vectors;
    vectors.push_back({0, 1, 2, 3});
    vectors.push_back({4, 5});
    vectors.push_back({6, 7, 8, 9, 10, 11});

    // 实现方式3 —— std::unique_ptr
    std::unique_ptr<int[]> upArray[3];
    upArray[0] = std::make_unique<int[]>(4);
    upArray[1] = std::make_unique<int[]>(2);
    upArray[2] = std::make_unique<int[]>(6);
    upArray[0][0] = 1;
    upArray[0][1] = 2;
    upArray[0][2] = 3;
    upArray[0][3] = 4;
    upArray[1][0] = 5;
    upArray[1][1] = 6;
    upArray[2][0] = 7;
    upArray[2][1] = 8;
    upArray[2][2] = 9;
    upArray[2][3] = 10;
    upArray[2][4] = 11;
    upArray[2][5] = 12;
}