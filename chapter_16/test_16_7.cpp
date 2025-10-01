//
// Created by lixia on 2025/10/1.
//

#include <iostream>
#include <string>

using namespace std;


template <typename T, unsigned Len>
size_t len(const T (&)[Len]) {
    return Len;
}



int main(int argc, char *argv[]) {
    const int nums[] = {1, 2, 3, 4, 5};
    cout << len(nums) << endl; // 5

    const string names[] = {"hello", "world", "c++", "c", "java"};
    cout << len(names) << endl; // 5
}
