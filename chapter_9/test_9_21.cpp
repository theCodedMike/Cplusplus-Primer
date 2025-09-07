//
// Created by lixia on 2025/9/6.
//

#include <vector>
#include <iostream>

#include "../include/Utils.h"
using namespace std;


int main(int argc, char *argv[]) {
    cout << "Please enter some words, 'quit' to quit: " << endl;

    vector<string> words;
    auto iter = words.begin();
    string word;
    while (cin >> word) {
        if (word == "quit")
            break;

        iter = words.insert(iter, word);
    }

    print_collection(words);
}
