//
// Created by lixia on 2025/8/19.
//

#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    string s = "What";
    cout << "Before replace: " << s << endl; // What

    for (auto ch: s) {
        ch = 'X';
    }

    cout << " After replace: " << s << endl; // What
}