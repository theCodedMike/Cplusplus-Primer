//
// Created by lixia on 2025/9/9.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "../include/Utils.h"

using namespace std;

void read_input(vector<string> &);
void elim_dups(vector<string> &);

int main(int argc, char *argv[]) {
    vector<string> words;
    read_input(words);
    cout << "Before dedup: "; print_collection(words);

    elim_dups(words);
    cout << " After dedup: "; print_collection(words);
}

void read_input(vector<string> &input) {
    cout << "Enter some words, 'quit' to quit: " << endl;
    string word;

    while (cin >> word) {
        if (word == "quit")
            break;

        input.push_back(word);
    }
}


void elim_dups(vector<string> &input) {
    std::ranges::sort(input);

    auto i = 0;
    for (auto j = 1; j < input.size(); ++j) {
        if (input[j] != input[i]) {
            ++i;
            input[i] = input[j];
        }
    }

    input.erase(input.begin() + i + 1, input.end());
}