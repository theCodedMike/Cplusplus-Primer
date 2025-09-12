//
// Created by lixia on 2025/9/12.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

void use_map();
void use_set();

int main(int argc, char *argv[]) {
    //use_map();
    use_set();
}

void use_map() {
    map<string, size_t> word_count;
    string word;
    while (cin >> word) {
        if (word == "quit")
            break;
        ++word_count[word];
    }

    for (const auto & w: word_count) {
        cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << endl;
    }
}

void use_set() {
    map<string, size_t> word_count;
    const set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    string word;

    while (cin >> word) {
        if (word == "quit")
            break;
        if (!exclude.contains(word))
            ++word_count[word];
    }

    for (const auto &[fst, snd]: word_count) {
        cout << fst << " occurs " << snd << ((snd > 1) ? " times" : " time") << endl;
    }
}