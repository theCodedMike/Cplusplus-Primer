//
// Created by lixia on 2025/9/6.
//

#include <list>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << "Please enter some words, 'quit' to quit: " << endl;

    list<string> words;
    string input;
    auto beg = words.cbegin();

    while (cin >> input) {
        if (input == "quit")
            break;
        beg = words.insert(beg, input); // 等价于push_front
    }

    for (const auto & word : words)
        cout << word << " ";
}
