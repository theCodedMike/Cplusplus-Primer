//
// Created by lixia on 2025/9/7.
//

#include <iostream>
#include <string>
using namespace std;

void my_replace(string &, const string &, const string &);

int main(int argc, char *argv[]) {
    string s1 = "tho";
    my_replace(s1, "tho", "though");
    cout << s1 << endl; // though

    string s2 = "thru";
    my_replace(s2, "thru", "through");
    cout << s2 << endl; // through

    string s3 = "haha";
    my_replace(s3, "ha", "fuck");
    cout << s3 << endl; // fuckfuck

    string s4 = "string";
    my_replace(s4, "xx", "fuck");
    cout << s4 << endl; // string
}

void my_replace(string &s, const string &oldVal, const string &newVal) {
    auto s_iter = s.begin();
    const auto old_iter = oldVal.cbegin();

    while (s_iter != s.end()) {
        if (*s_iter == *old_iter) {
            bool match = true;
            auto old_curr = old_iter;
            auto s_curr = s_iter;
            while (old_curr != oldVal.end()) {
                if (*old_curr != *s_curr) {
                    match = false;
                    break;
                }
                ++old_curr;
                ++s_curr;
            }

            if (match) {
                s.erase(s_iter, s_curr);
                s.insert(s_iter, newVal.begin(), newVal.end());
            }
        }

        ++s_iter;
    }
}