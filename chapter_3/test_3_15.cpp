//
// Created by lixia on 2025/8/19.
//
#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::cin;
using std::cout;
using std::string;


int main(int argc, char *argv[]) {
    vector<string> lines;
    string line;

    while (cin >> line)
        lines.push_back(line);

    for (auto l: lines) {
        cout << l << '\n';
    }
}
