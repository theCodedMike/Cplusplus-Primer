//
// Created by lixia on 2025/9/7.
//

#include <forward_list>
#include <string>
#include "../include/Utils.h"
using namespace std;

void insert_string(forward_list<string> &, const string &, const string &);

int main(int argc, char *argv[]) {
    forward_list<string> flist = {"1", "2", "3", "4"};
    string s1 = "3";
    string s2 = "5";
    insert_string(flist, s1, s2);
    print_collection(flist); // [1, 2, 3, 5, 4]

    s1 = "10";
    s2 = "10";
    insert_string(flist, s1, s2);
    print_collection(flist); // [1, 2, 3, 5, 4, 10]

    flist.clear();
    insert_string(flist, s1, s2);
    print_collection(flist); // [10]
}

void insert_string(forward_list<string> &flist, const string &s1, const string &s2) {
    auto prev = flist.cbefore_begin();
    auto curr = flist.cbegin();
    auto end = flist.cend();

    while (curr != end) {
        if (*curr == s1) {
            flist.insert_after(curr, s2);
            return;
        }
        prev = curr;
        ++curr;
    }

    flist.insert_after(prev, s2);
}