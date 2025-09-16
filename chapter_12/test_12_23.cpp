//
// Created by lixia on 2025/9/16.
//
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

char * splice(const char *, const char *);

int main(int argc, char *argv[]) {
    const char * s1 = "hello";
    const char * s2 = "world";
    const auto new_s = splice(s1, s2);
    cout << new_s << endl;
    delete [] new_s;
}

char * splice(const char *s1, const char *s2) {
    size_t sz1 = strlen(s1);
    size_t sz2 = strlen(s2);

    const auto new_s = new char[sz1 + sz2 + 1];
    size_t idx = 0;
    for (size_t i = 0; i < sz1; ++i, ++idx)
        new_s[idx] = s1[i];
    for (size_t i = 0; i < sz2; ++i, ++idx) {
        new_s[idx] = s2[i];
    }
    new_s[idx] = '\0';

    return new_s;
}