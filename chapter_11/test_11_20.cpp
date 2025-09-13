//
// Created by lixia on 2025/9/13.
//

#include <iostream>
#include <map>

using namespace std;


int main(int argc, char *argv[]) {
    map<string, unsigned> word_counter;
    string input;

    cout << "Enter some words, 'quit' to quit:" << endl;
    while (cin >> input) {
        if (input == "quit")
            break;

        if (auto [target_iter, is_success] = word_counter.insert({input, 1}); !is_success) {
            ++target_iter->second;
        }
    }

    for (const auto & [word, count]: word_counter) {
        cout << word << " occurs " << count << ((count > 1) ? " times" : " time") << endl;
    }
}
