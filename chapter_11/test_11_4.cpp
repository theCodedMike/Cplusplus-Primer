//
// Created by lixia on 2025/9/12.
//

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void normalize(string &);


int main(int argc, char *argv[]) {
    map<string, size_t> word_count;
    string word;

    cout << "Enter some words, 'quit' to quit:" << endl;
    while (cin >> word) {
        if (word == "quit")
            break;
        normalize(word);
        ++word_count[word];
    }

    for (const auto &[fst, snd]: word_count) {
        cout << fst << " occurs " << snd << ((snd > 1) ? " times" : " time") << endl;
    }
}

void normalize(string &word) {
    // l_trim
    const auto alpha_beg = ranges::find_if(word, [](const char c) {
        return isalpha(c);
    });
    word.erase(word.begin(), alpha_beg);
    // r_trim
    const auto alpha_end = ranges::find_if(word.crbegin(), word.crend(), [](const char c) {
        return isalpha(c);
    });
    word.erase(alpha_end.base(), word.end());
    // tolower
    ranges::transform(word, word.begin(), [](const char c) {
        return tolower(c);
    });
}
