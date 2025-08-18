//
// Created by lixia on 2025/8/18.
//

#include <iostream>
#include <string>
using std::getline;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s1 == s2 " << (s1 == s2 ? "(true)" : "(false)") << endl;
    cout << "larger string: " << (s1 > s2 ? s1 : s2) << endl;
    cout << "s1.size == s2.size " << (s1.size() == s2.size() ? "(true)" : "(false)") << endl;
    cout << "longer string: " << (s1.size() > s2.size() ? s1 : s2) << endl;
}

