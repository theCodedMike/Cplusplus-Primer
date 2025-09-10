//
// Created by lixia on 2025/9/10.
//

#include <iostream>
using namespace std;


int main(int argc, char *argv[]) {
    auto sum = [](int a, int b) -> double {
        return a + b;
    };

    cout << sum(10, 22) << endl; // 32
}
