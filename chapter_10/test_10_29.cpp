//
// Created by lixia on 2025/9/11.
//

#include <iterator>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream fin("./test_10_29.txt");
    std::istream_iterator<string> is_iter(fin), eof;
    vector<string> content;

    while (is_iter != eof) {
        content.push_back(*is_iter++);
    }

    for (const auto & word: content) {
        cout << word << endl;
    }
}
