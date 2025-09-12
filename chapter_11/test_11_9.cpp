//
// Created by lixia on 2025/9/12.
//
#include <iostream>
#include <map>
#include <list>
#include <fstream>
#include <sstream>
#include "../include/Utils.h"
using namespace std;


int main(int argc, char *argv[]) {
    ifstream fin("./test_11_9.txt");
    if (!fin.is_open())
        throw runtime_error("can't open file");

    unsigned line_number = 0;
    string line, word;
    map<string, list<unsigned>> words_count;
    istringstream sin;
    while (getline(fin, line)) {
        ++line_number;

        sin.str(line);
        while (sin >> word) {
            words_count[word].push_back(line_number);
        }
        sin.clear();
    }

    for (const auto&[fst, snd]: words_count) {
        cout << fst << ": "; print_collection(snd);
    }
}
