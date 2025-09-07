//
// Created by lixia on 2025/9/8.
//

#include <iostream>
#include <string>
using namespace std;

const string digits = "0123456789";

void find_digits(const string &);
void find_characters(const string &);

int main(int argc, char *argv[]) {
    string s = "ab2c3d7R4E6";
    find_digits(s);
    find_characters(s);

    // 2: 2
    // 3: 4
    // 7: 6
    // 4: 8
    // 6: 10
    // a: 0
    // b: 1
    // c: 3
    // d: 5
    // R: 7
    // E: 9
}

void find_digits(const string &s) {
    string::size_type pos = 0;
    while ((pos = s.find_first_of(digits, pos)) != string::npos) {
        cout << s[pos] << ": " << pos << endl;
        ++pos;
    }
}

void find_characters(const string &s) {
    string::size_type pos = 0;
    while ((pos = s.find_first_not_of(digits, pos)) != string::npos) {
        cout << s[pos] << ": " << pos << endl;
        ++pos;
    }
}