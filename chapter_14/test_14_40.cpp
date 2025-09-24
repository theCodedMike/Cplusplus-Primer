//
// Created by lixia on 2025/9/24.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SizeCmp {
public:
    bool operator()(const string &s1, const string &s2) const {
        return s1.size() < s2.size();
    }
};

void biggies(vector<string> & words, vector<string>::size_type sz) {
    std::ranges::stable_sort(words, SizeCmp());
}

int main(int argc, char *argv[]) {
    vector<string> words = {
        "11111",
        "1111",
        "111",
        "11",
        "1"
    };

    biggies(words, 5);

    for (auto & word: words) {
        cout << word << endl;
    }
}
