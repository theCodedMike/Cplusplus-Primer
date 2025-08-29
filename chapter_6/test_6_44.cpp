//
// Created by lixia on 2025/8/29.
//

#include "./../include/Chapter6.h"

int main(int argc, char *argv[]) {
    string s1 = "hello";
    string s2 = "world";
    cout << is_shorter(s1, s2) << endl; // 0
}

inline auto is_shorter(const string &s1, const string &s2) -> bool {
    return s1.size() < s2.size();
}