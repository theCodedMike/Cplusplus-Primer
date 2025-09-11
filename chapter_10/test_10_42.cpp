//
// Created by lixia on 2025/9/11.
//

#include <iostream>
#include <string>
#include <list>
#include "./../include/Utils.h"
using namespace std;

void read_input(list<string> &);
void elim_dups(list<string> &);

int main(int argc, char *argv[]) {
    list<string> words;
    read_input(words);
    cout << "Before dedup: "; print_collection(words);

    elim_dups(words);
    cout << " After dedup: "; print_collection(words);
}


void read_input(list<string> &words) {
    string word;
    cout << "Enter some words('quit' to quit): " << endl;
    while (cin >> word) {
        if (word == "quit")
            break;

        words.push_back(word);
    }
}

void elim_dups(list<string> &words) {
    words.sort();

    auto curr = words.begin();
    ++curr;
    auto prev = words.cbegin();

    while (curr != words.end()) {
        if (*curr == *prev) {
            curr = words.erase(curr);
        } else {
            prev = curr;
            ++curr;
        }
    }
}