//
// Created by lixia on 2025/9/8.
//

#include <vector>
#include <iostream>
#include <string>
using namespace std;

double sum(const vector<string> &);

int main(int argc, char *argv[]) {
    vector<string> v = {"10", "-1", "100"};
    cout << sum(v) << endl; // 109
}

double sum(const vector<string> &v) {
    double sum = 0;
    for (const auto &s: v) {
        sum += stod(s);
    }
    return sum;
}