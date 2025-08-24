//
// Created by lixia on 2025/8/24.
//

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int i = 10;
    double d = 3.14159;

    i *= static_cast<int>(d);

    cout << i << endl; // 30
}
