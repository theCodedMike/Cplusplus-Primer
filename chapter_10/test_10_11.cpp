//
// Created by lixia on 2025/9/10.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "../include/Utils.h"
using namespace std;

void elim_dups(vector<string> &);

int main(int argc, char *argv[]) {
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elim_dups(words);
    cout << "After elim dups: "; print_collection(words);
}

bool is_shorter(const string &s1, const string &s2) {
    return s1.size() < s2.size();
}

void elim_dups(vector<string> &vs) {
    ranges::stable_sort(vs, is_shorter);
    cout << "After sort: "; print_collection(vs);
    auto end_unique = ranges::unique(vs).begin();
    vs.erase(end_unique, vs.end());
}