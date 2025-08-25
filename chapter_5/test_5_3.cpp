//
// Created by lixia on 2025/8/25.
//

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int sum = 0, val = 1;

    while (val <= 10)
        sum += val++;

    cout << "Sum of 1 to 10 inclusive is " << sum << endl;

    return 0;
}
