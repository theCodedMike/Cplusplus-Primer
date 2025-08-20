//
// Created by lixia on 2025/8/20.
//

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::islower;

int main(int argc, char *argv[]) {
    string word;
    vector<string> input;

    while (cin >> word) {
        if ("quit" == word)
            break;

        input.push_back(word);
    }

    for (auto &word: input) {
        for (char &ch: word) {
            if (islower(ch))
                ch = toupper(ch);
        }
    }

    for (auto word: input) {
        cout << word << endl;
    }
}
