//
// Created by lixia on 2025/8/27.
//

#include "./../include/Chapter6.h"

int main(int argc, char *argv[]) {
    string s1 = "hello World";
    cout << have_upper_letter(s1) << endl; // 1
    string s2 = "hello world";
    cout << have_upper_letter(s2) << endl; // 0

    string s3 = "Hello World";
    all_to_lower(s3);
    cout << s3 << endl;
}

bool have_upper_letter(const string &s) {
    /*for (auto &ch: s) {
        if (isupper(ch))
            return true;
    }
    return false;*/

    return std::any_of(s.cbegin(), s.cend(), [](const char &ch) { return isupper(ch); });
}

void all_to_lower(string &s) {
    for (auto &ch: s) {
        if (isupper(ch))
            ch = static_cast<char>(tolower(ch));
    }
}