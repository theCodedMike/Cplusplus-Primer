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
    for (auto i = 0; i < s.size(); i++) {
        if (s[i] == oldVal[0]) {
            bool match = true;
            for (auto j = 0; j < oldVal.size(); ++j) {
                if (s[i + j] != oldVal[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                s.replace(i, oldVal.size(), newVal);
            }
        }
    }
}