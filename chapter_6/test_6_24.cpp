//
// Created by lixia on 2025/8/28.
//

#include <iostream>
using namespace std;

void print(const int ia[10]);

int main(int argc, char *argv[]) {
    int arr[10] = {-1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
    print(arr);
    int arr2[5] = {2, 3, 4, 5, 6};
    print(arr2); // 会打印10个，但是后5个值不一定有效
    int arr3[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    print(arr3); // 只打印10个
}

void print(const int ia[10]) {
    for (size_t i = 0; i != 10; ++i)
        cout << ia[i] << ' ';
    cout << endl;
}