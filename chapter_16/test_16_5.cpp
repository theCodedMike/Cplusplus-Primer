//
// Created by lixia on 2025/10/1.
//
#include <string>
#include <iostream>
#include <array>

using namespace std;

template <typename T, unsigned Len>
void print(const T (&arr)[Len]) {
    for (auto i = 0; i < Len; ++i)
        cout << arr[i] << " ";
}
int main(int argc, char *argv[]) {
    const string names[] = {"Jack", "Mike", "Tomas", "Joe"};
    print(names);
    cout << endl;

    /*
    // ❌
    const array nums = {1, 2, 3, 4, 5};
    print(nums);*/

    const int nums[] = {1, 2, 3, 4, 5};
    print(nums);
}
