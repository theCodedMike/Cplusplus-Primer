//
// Created by lixia on 2025/9/10.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(int argc, char *argv[]) {
    const vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle", "6666666"};
    const string::size_type sz = 6;
    const ptrdiff_t count = std::ranges::count_if(words.cbegin(), words.cend(), [=](const string &word) {
        return word.size() > sz;
    });

    cout << count << endl;
}
