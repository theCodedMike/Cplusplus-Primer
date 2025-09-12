//
// Created by lixia on 2025/9/12.
//

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../include/Sales_data.h"
using namespace std;

void use_map();
void use_set();
void initialize();


int main(int argc, char *argv[]) {
    //use_map();
    //use_set();
    initialize();
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

void initialize() {
    const map<string, string> authors = {
        {"Joyce", "James"},
        {"Austen", "Jane"},
        {"Dickens", "Charles"}
    };

    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }
    set<int> iset(ivec.cbegin(), ivec.cend());
    multiset<int> miset(ivec.cbegin(), ivec.cend());
    cout << ivec.size() << endl; // 20
    cout << iset.size() << endl; // 10
    cout << miset.size() << endl;// 20

    // 严格弱序
    multiset<Sales_data, decltype(compare_isbn) *> bookstore(compare_isbn);
}

void use_pair() {
    pair<string, string> anon;
    pair<string, string> author("Hello", "Json");
    pair<string, string> author2{"Tom", "Jack"};
    pair<string, string> author3 = {"Lee", "Zhang"};

}