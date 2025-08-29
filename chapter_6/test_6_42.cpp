//
// Created by lixia on 2025/8/29.
//

#include "./../include/Chapter6.h"

auto make_plural(size_t ctr, const string &word, const string &ending = "s") -> string;

int main(int argc, char *argv[]) {
    string s1 = "success";
    string s2 = "failure";

    string r1 = make_plural(s1.size(), s1, "es");
    cout << s1 << " -> " << r1 << endl;
    string r2 = make_plural(s2.size(), s2);
    cout << s2 << " -> " << r2 << endl;
}

auto make_plural(const size_t ctr, const string &word, const string &ending) -> string {
    return (ctr > 1) ? word + ending : word;
}