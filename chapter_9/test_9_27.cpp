//
// Created by lixia on 2025/9/7.
//

#include <forward_list>

#include "../include/Utils.h"
using namespace std;

void remove_odd(forward_list<int> &);

int main(int argc, char *argv[]) {
    forward_list<int> flist = {3, 3, 2, 5, 7, 10, 0};
    remove_odd(flist);
    print_collection(flist); // [2, 10, 0]

    forward_list<int> flist2;
    remove_odd(flist2);
    print_collection(flist2); // []

    forward_list<int> flist3 = {1, 1, 1, 1};
    remove_odd(flist3);
    print_collection(flist3); // []
}

void remove_odd(forward_list<int> & flist) {
    auto prev = flist.cbefore_begin();
    auto curr = flist.cbegin();
    auto end = flist.cend();

    if (end == curr)
        return;
    while (curr != end) {
        if (*curr % 2 == 1) {
            curr = flist.erase_after(prev);
        } else {
            prev = curr;
            ++curr;
        }
    }
}
