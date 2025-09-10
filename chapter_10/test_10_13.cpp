//
// Created by lixia on 2025/9/10.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool size_great_5(const string &s) {
    return s.size() >= 5;
}

int main(int argc, char *argv[]) {
    vector<string> words = {"hello", "Mike", "Hi", "work", "hard", "computer", "patience"};

    auto end_part = std::ranges::partition(words, size_great_5).begin();

    for (auto it = words.cbegin(); it != end_part; ++it) {
        cout << *it << endl;
    }
    // hello
    // patience
    // computer
}
