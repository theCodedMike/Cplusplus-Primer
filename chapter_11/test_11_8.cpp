//
// Created by lixia on 2025/9/12.
//

#include <iostream>
#include <vector>

#include "../include/Utils.h"

using namespace std;


int main(int argc, char *argv[]) {
    vector<string> words_count;
    string word;

    cout << "Enter some words:" << endl;
    while (cin >> word) {
        if (word == "quit")
            break;

        if (const auto pos = ranges::find(words_count, word); pos == words_count.end())
            words_count.push_back(word);
    }

    print_collection(words_count);
}
