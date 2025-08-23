//
// Created by lixia on 2025/8/23.
//

#include <iostream>
using std::cout;
using std::endl;
using std::string;


int main(int argc, char *argv[]) {
    string s = "word";
    string p1 = s + (s[s.size() - 1] == 's' ? "" : "s");
    cout << p1 << endl; // words
}
