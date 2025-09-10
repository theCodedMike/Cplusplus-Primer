//
// Created by lixia on 2025/9/10.
//

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int i = 100;
    auto add = [i](int j) -> double {
        return i + j;
    };

    cout << add(3) << endl; // 103
}
