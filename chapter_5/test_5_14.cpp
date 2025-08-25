//
// Created by lixia on 2025/8/25.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct WordData {
    string word;
    unsigned int count;
};

int main(int argc, char *argv[]) {
    vector<WordData> counter;
    string input;
    bool find = false;

    while (cin >> input && input != "quit") {
        find = false;

        for (auto &[word, count]: counter) {
            if (word == input) {
                ++count;
                find = true;
                break;
            }
        }

        if (!find)
            counter.push_back(WordData {input, 1});
    }

    const auto result = max_element(
        counter.begin(), counter.end(),
        [](const WordData &a, const WordData &b){return a.count < b.count;});
    cout<< "\"" << result->word << "\": " << result->count << endl;
}
