//
// Created by lixia on 2025/9/10.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void biggies(vector<string> &, string::size_type);

int main(int argc, char *argv[]) {
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    biggies(words, 5);
}


void biggies(vector<string> &words, string::size_type sz) {
    std::ranges::sort(words);
    auto end_unique = std::ranges::unique(words);
    words.erase(end_unique.begin(), words.end());

    std::ranges::sort(words, [](const string &a, const string &b) {
        return a.size() < b.size();
    });

    auto begin_larger = std::ranges::partition(words, [sz](const string &word) {
        return word.size() < sz;
    });

    const ptrdiff_t count = words.end() - begin_larger.begin();
    cout << count << (count > 1 ? " words" : " word") << " of length " << sz << " or longer" << endl;

    std::for_each(begin_larger.begin(), words.end(), [](const string &word) {
        cout << word << " ";
    });
    cout << endl;
}
