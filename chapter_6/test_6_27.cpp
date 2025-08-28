//
// Created by lixia on 2025/8/28.
//

#include <iostream>
#include <initializer_list>
using namespace std;

long long sum(initializer_list<int> vals);

int main(int argc, char *argv[]) {
    initializer_list<int> il = {1, 2, 3, 4, 5};
    cout << sum(il) << endl;
}

long long sum(initializer_list<int> vals) {
    long long sum = 0;
    for (const int val: vals) {
        sum += val;
    }
    return sum;
}