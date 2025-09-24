//
// Created by lixia on 2025/9/24.
//
#include <iostream>

using namespace std;

class CmpInt {
public:
    int operator()(const bool larger, const int i1, const int i2) const {
        if (larger)
            return i1;
        return i2;
    }
};

int main(int argc, char *argv[]) {
    const CmpInt cmp_int;
    const int i1 = 10;
    const int i2 = 20;
    cout << cmp_int(i1 > i2, i1, i2) << endl; // 20
}
